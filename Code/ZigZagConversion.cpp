#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (size == 0 || numRows < 0)
            return "";

        string ret = "";
        int i, j, k;

        char table[numRows][size];
        for (i = 0; i < numRows; ++i)
            for (j = 0; j < size; ++j)
                table[i][j] = 0;

        for (i = 0; i < size;){
            for (j = 0; j < numRows && i < size; ++j, ++i) {
                table[j][i] = s[i];
            }
            for (k = numRows-2; k >= 1 && i < size; --k, ++i) {
                table[k][i] = s[i];
            }
        }

        for (i = 0; i < numRows; ++i)
            for (j = 0; j < size; ++j)
                if (table[i][j])
                    ret += table[i][j];
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = sol.convert(s, numRows);
    cout << "---" << endl;
    cout << result << endl;
}
