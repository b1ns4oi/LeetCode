
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::copy;


class Solution {
public:
    vector<vector<string> > partition(string s) 
	{
        
		vector<vector<string> > ret;
		
		int i, j, N = s.size();
		bool **a = new bool*[N];
		for(i = 0; i < N; ++i)
			a[i] = new bool[N];
			
		// constructor auxiliary boolean 2 dimensional array
		for(i = 0; i < N; ++i)
			for(j = i; j < N; ++j)
				a[i][j] = (i == j) ? true: false;
		
		for(i = N-1; i >= 0; --i)
			for(j = i+1; j < N; ++j)
				if(s[i] == s[j] && (j-i == 1 || (j-i > 1 && a[i+1][j-1])))
					a[i][j] = true;
				else a[i][j] = false;

		vector<string> vec;
		parti_helper(ret, a, s, vec, 0);
		
		// destruct a[][]
		for(i = 0; i < N; ++i)
			delete[] a[i];
		delete[] a;
		
		return ret;
    }
	
private:
	void parti_helper(vector<vector<string> >& ret, bool **a, const string& s, vector<string>& vec, int start) 
	{
		size_t N = s.size();
		if(start == N) {
			ret.push_back(vec);
			return;
		}
		for(int i = start; i < N; ++i) {
			if(a[start][i]) {
				vec.push_back(s.substr(start, i-start+1));
				parti_helper(ret, a, s, vec, i+1);
				vec.erase(vec.end()-1);
			}
		}
	} 
};

int main()
{
	Solution sol;
	vector<vector<string> > ret = sol.partition("hiih");
	for(int i = 0; i < ret.size(); ++i) {
		copy(ret[i].begin(), ret[i].end(), std::ostream_iterator<string>(cout, " "));
		cout << endl;
	}
}