#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row, col;
        int m = matrix.size(), n;
        vector<int> res;
        if (m == 0)
            return res;

        n = matrix[0].size();
        spiralOrder_helper(matrix, m, n, 0, 0, res);
        return res;
    }

private:
    void spiralOrder_helper(
        vector<vector<int>>& matrix, 
        int n_rows, 
        int n_cols, 
        int row_start, 
        int col_start, 
        vector<int>& res) 
    {
        if (n_rows <= 0 || n_cols <= 0)
            return;

        int i, j;

        for (j = col_start; j < n_cols+col_start; ++j)
            res.push_back(matrix[row_start][j]);

        for (i = row_start+1; i < row_start+n_rows; ++i)
            res.push_back(matrix[i][col_start+n_cols-1]);

        if (n_rows > 1)
            for (j = col_start+n_cols-2; j >= col_start; --j)
                res.push_back(matrix[row_start+n_rows-1][j]);

        if (n_cols > 1)
            for (i = row_start+n_rows-2; i > row_start; --i)
                res.push_back(matrix[i][col_start]);

        spiralOrder_helper(matrix, n_rows-2, n_cols-2, row_start+1, col_start+1, res);
    }
};
int main() 
{
    Solution sol;
    vector<vector<int> > matrix = {{1,2,3}};
    vector<int> result = sol.spiralOrder(matrix);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}