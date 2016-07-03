#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        /* integer is faster than bool: http://stackoverflow.com/questions/32821113/why-vectorint-is-faster-than-vectorbool-in-the-following-case */
        vector<int> col(n, 0);
        vector<int> diag45(2*n-1, 0);
        vector<int> diag135(2*n-1, 0);
        int count = 0;

        totalNQueens_recur(0, col, diag45, diag135, count);
        return count;
    }

private:
    void totalNQueens_recur(int row, vector<int>& col, vector<int>& diag45, vector<int>& diag135, int& count) {
        int n = col.size();

        if (row == n) {
            ++count;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!col[j] && !diag45[j+row] && !diag135[n-j+row-1]) {
                col[j] = diag45[j+row] = diag135[n-j+row-1] = 1;
                totalNQueens_recur(row+1, col, diag45, diag135, count);
                col[j] = diag45[j+row] = diag135[n-j+row-1] = 0;
            }
        }
    }
};

int main()
{
    Solution sol;
    int res = sol.totalNQueens(8);

    cout << res << endl;
}