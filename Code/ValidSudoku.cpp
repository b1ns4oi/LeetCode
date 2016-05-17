#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // ugly version
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> v(10, false);

        // verify rows
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                if (v[board[i][j]-'0'])
                    return false;
                v[board[i][j]-'0'] = true;
            }
            clean_v(v);
        }
        clean_v(v);

        // verify columns
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.')
                    continue;
                if (v[board[j][i]-'0'])
                    return false;
                v[board[j][i]-'0'] = true;
            }
            clean_v(v);
        }
        clean_v(v);

        // verify sub-boxes
        int offset_i, offset_j;
        for (offset_i = 0; offset_i < 9; offset_i += 3) {
            for (offset_j = 0; offset_j < 9; offset_j += 3) {
                // iterate and verify a sub-box
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (board[i+offset_i][j+offset_j] == '.')
                            continue;
                        if (v[board[i+offset_i][j+offset_j] - '0'])
                            return false;
                        v[board[i+offset_i][j+offset_j] - '0'] = true;
                    }
                }
                clean_v(v);
            }
        }
        return true;
    }
private:
    void clean_v(vector<bool>& v) {
        for (int i = 0; i < v.size(); ++i)
            v[i] = false;
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

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> v = {"....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"};
    vector<vector<char> > vv = construct(v);
    bool result1 = sol.isValidSudoku(vv);
    cout << result1 << endl;
}