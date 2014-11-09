
//
// Buggy !!!
//
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstddef>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    vector<vector<string> > partition(string s) {
    	vector<vector<string> > ret;
    	size_t n = strlen(s.c_str());
        bool a[n][n];
        for(size_t i = 0; i < n; ++i)
        	for(size_t j = i; j < n; ++j)
        		a[i][j] = (i == j ? true : false);
        // set a[][] appropriatly
        for(size_t i = n-1; i >= 0; --i) 
        	for(size_t j = i+1; j < n; ++j)
        		if(s[i] == s[j] && (j-i < 2 || a[i+1][j-1]))
        			a[i][j] = true;
        
        vector<string> vec;
        parti_helper(ret, a, 0, s, vec);
        return ret;
    }

private:
	void parti_helper(vector<vector<string> >& ret, 
		bool** a, 
		size_t start, 
		const string& s, 
		vector<string>& vec)
	{
		size_t n = strlen(s.c_str());
		if(start = n) {
			ret.push_back(vec);
			//vec.erase(vec.end()-1);
			return;
		}
		for(size_t i = start; i < n; ++i) {
			if(a[start][i]) {
				vec.push_back(s.substr(start, i-start+1));
				parti_helper(ret, a, i+1, s, vec);
				vec.erase(vec.end()-1);
			}
		}	
	}
};

int main()
{

}