#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solveSudoku1(vector<vector<char>>& board) {
        if (board.empty())
            return;
        solve1(board);
    }

    void solveSudoku2(vector<vector<char>>& board) {
        if (board.empty())
            return;
        solve2(board, 0, 0);
    }

private:
    bool solve1(vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char e = '1'; e <= '9'; ++e) {
                        if (is_valid(board, i, j, e)) {
                            board[i][j] = e;
                            if (solve1(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    // Recursively
    bool solve2(vector<vector<char> >& board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return solve2(board, i+1, 0);

        if (board[i][j] != '.')
            return solve2(board, i, j+1);

        for (char e = '1'; e <= '9'; ++e) {
            if (is_valid(board, i, j, e)) {
                board[i][j] = e;
                if (solve2(board, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    // verify if it's a valid sudoku after insert element 'e' into position board[i][j]
    bool is_valid(vector<vector<char> >& board, int i, int j, char e) {
        // verify row
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] == e)
                return false;
        }

        // verify column
        for (int k = 0; k < 9; ++k) {
            if (board[k][j] == e)
                return false;
        }

        // verify sub-box
        for (int l = i/3*3; l < i/3*3 + 3; ++l) {
            for (int k = j/3*3; k < j/3*3 + 3; ++k) {
                if (board[l][k] == e)
                    return false;
            }
        }
        return true;
    }
};

// construct sudoku structure
vector<vector<char> > construct(vector<string>& v) {
    vector<vector<char> > vv(9, vector<char>());
    for (int i = 0; i < 9; ++i) {
        string s = v[i];
        for (int j = 0; j < 9; ++j) {
            vv[i].push_back(s[j]);
        }
    }
    // print sub-boxes
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return vv;
}
