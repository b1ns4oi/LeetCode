#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        do_write(res, 0, 0, n, n, 1);
        return res;
    }

private:
    void do_write(vector<vector<int>>& res, int row, int col, int n_rows, int n_cols, int i) {
        if (n_rows <= 0 || n_cols <= 0)
            return;
        else if (n_rows == 1 && n_cols == 1) {
            res[row][col] = i;
            return;
        }

        int j, k;

        for (j = col; j < col+n_cols-1; ++j) {
            res[row][j] = i++;
        }

        for (k = row; k < row+n_rows-1; ++k) {
            res[k][j] = i++;
        }

        for (; j > col; --j) {
            res[k][j] = i++;
        }

        for (; k > row; --k) {
            res[k][j] = i++;
        }

        do_write(res, row+1, col+1, n_rows-2, n_cols-2, i);
    }
};

int main() 
{
    Solution sol;
    vector<vector<int> > result = sol.generateMatrix(5);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}