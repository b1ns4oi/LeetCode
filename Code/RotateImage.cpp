#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int len = matrix.size();
        vector<vector<int> > res(len, vector<int>(len, 0));

        for (int i = 0; i < len; ++i) {
        	for (int j = 0; j < len; ++j) {
        		res[i][j] = matrix[len-j-1][i];
        	}
        }
        matrix.swap(res);
    }

    // reference: https://leetcode.com/discuss/20589/a-common-method-to-rotate-the-image
    //
    // Really COOL solution
    void rotate_in_place(vector<vector<int>>& matrix) {
    	reverse(matrix.begin(), matrix.end());
    	for (int i = 0; i < matrix.size(); ++i) {
    		for (int j = i+1; j < matrix.size(); ++j) {
    			iter_swap(&matrix[i][j], &matrix[j][i]);
    		}
    	}
    }

    // I came with this in-place solution first
    // Althrough the idea is not as cool as above one, but it can solve the problem
    // Moreover, should pay attention to the implementation details (some index are hard to capture)
    void rotate_in_place2(vector<vector<int>>& matrix) {
    	int n = matrix.size();

    	for (int i = 0; i < n/2; ++i) {
    		for (int j = i; j < n-1-i; ++j) {
    			int tmp = matrix[i][j];
    			matrix[i][j] = matrix[n-1-j][i];
    			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
    			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
    			matrix[j][n-1-i] = tmp;
    		}
    	}
    }
};

int main() 
{
	vector<vector<int> > matrix = {{1,2,3,4}, {4,5,6,7}, {7,8,9,10}, {11,12,13,14}};

	Solution sol;
	sol.rotate_in_place2(matrix);

	int len = matrix.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}