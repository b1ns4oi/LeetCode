#include <iostream>
#include <vector>

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
};

int main() 
{
	vector<vector<int> > matrix = {{1,2,3,4}, {4,5,6,7}, {7,8,9,10}, {11,12,13,14}};

	Solution sol;
	sol.rotate(matrix);

	int len = matrix.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}