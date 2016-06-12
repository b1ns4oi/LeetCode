#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // brute-force with back-tracking
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> s(n, string(n, '.'));

        solveNQueens_recur(res, s, 0, n);
        return res;
    }

private:
    void solveNQueens_recur(vector<vector<string> >& res, vector<string>& s, int row, int n) {
        if (row == n) {
            res.push_back(s);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (is_valid(s, row, col)) {
                s[row][col] = 'Q';
                solveNQueens_recur(res, s, row+1, n);
                s[row][col] = '.';
            }
        }
    }

    // Check if 's' is valid (with s[row][col] marked as 'Q')
    bool is_valid(vector<string>& s, int row, int col) {
        int n = s.size();
        int i, j;

        // check column
        for (i = 0; i < row; ++i)
            if (s[i][col] == 'Q')
                return false;

        // check 135 diagnol
        for (i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) {
            if (s[i][j] == 'Q')
                return false;
        }

        // check 45 diagnol
        for (i = row-1, j = col+1; i >= 0 && j < n; --i, ++j)
            if (s[i][j] == 'Q')
                return false;

        return true;
    }
};

int main() 
{
	Solution sol;
    vector<vector<string>> res = sol.solveNQueens(8);
    
    // for (int i = 0; i < res.size(); ++i) {
    //     for (int j = 0; j < res[i].size(); ++j) {
    //         cout << res[i][j] << endl;
    //     }
    //     cout << " --------------------- " << endl;
    // }
	cout << res.size() << endl;
}