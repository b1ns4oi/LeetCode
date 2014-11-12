


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
using std::min;

// buggy : Time Limit Exceeded

// class Solution {
// public:
//     int minCut(string s) {
//         int i, j, N = s.size();
// 		bool **a = new bool*[N];
// 		for(i = 0; i < N; ++i)
// 			a[i] = new bool[N];
		
// 		int **result = new int*[N];
// 		for(i = 0; i < N; ++i)
// 			result[i] = new int[N];
			
// 		for(i = 0; i < N; ++i)
// 			for(j = i; j < N; ++j)
// 				result[i][j] = (i == j) ? 0 : -1;
		
// 		for(i = 0; i < N; ++i)
// 			for(j = i; j < N; ++j) {
// 				if(i == j) {
// 					a[i][j] = true;
// 					result[i][j] = 0;
// 				}
// 				else {
// 					a[i][j] = false;
// 					result[i][j] = -1;
// 				}
// 			}
	
		
// 		for(i = N-1; i >= 0; --i)
// 			for(j = i+1; j < N; ++j)
// 				if(s[i] == s[j] && (j-i == 1 || (j-i > 1 && a[i+1][j-1]))) {
// 					a[i][j] = true;
// 					result[i][j] = 0;
// 				}

// 		int ret = parti_helper(a, s, 0, N-1, result);
		
// 		// destruct a[][] and result[][]
// 		for(i = 0; i < N; ++i) {
// 		    delete[] a[i];
// 		    delete[] result[i];
// 		}
// 		delete[] a;
// 		delete[] result;
		
// 		return ret;
//     }
	
// private:
// 	int parti_helper(bool **a, const string& s, int start, int end, int **result) 
// 	{
		
// 		if(end < start) 
// 			return 0;
// 		if(start == end || a[start][end])
// 			return (result[start][end] = 0);
// 		if(result[start][end] >= 0) return result[start][end];
		
// 		// try the partition after element in [start, end)
// 		int current_min = end-start, m;
// 		for(int i = start; i < end; ++i) {
// 			current_min = min(current_min, parti_helper(a, s, start, i, result) + 1 + parti_helper(a, s, i+1, end, result));
// 			result[start][end] = current_min;
// 		}
			
		
// 		return current_min;
// 	}  
// };



#include <string>
#include <algorithm>

using std::min;
using std::string;

class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		bool b[n][n];
		int a[n+1];

		for(int i = 0; i < n; ++i) {
			b[i][i] = true;
		}
		
		for(int i = n-1; i >= 0; --i)
			for(int j = i+1; j < n; ++j) {
				if(s[i] == s[j] && (j - i == 1 || b[i+1][j-1])) 
					b[i][j] = true;
				else 
					b[i][j] = false;
			}

		for(int i = 0; i <= n; ++i) 
			a[i] = n-i-1;
		
		for(int i = n-1; i >= 0; --i) {
			for(int j = i; j < n; ++j) {
				if(b[i][j])
					a[i] = min(a[i], 1 + a[j+1]);
			}
		}
		return a[0];
	}
};


int main()
{
	Solution sol;
	string s = "a";
	int ret = sol.minCut(s);

	cout << ret << endl;
	cout << s << endl;

	for(int i = 0; i < s.size(); ++i)
		if(s[i] != 'a')
			cout << s[i] << " " << i << endl;
}























