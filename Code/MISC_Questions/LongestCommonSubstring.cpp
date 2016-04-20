#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonSubstring(string &s1, string &s2) {
        int size1 = s1.size(), size2 = s2.size();
        if (size1 == 0 || size2 == 0)
            return "";

        vector< vector<int> > index(128, vector<int>());
        int i, j, k, l, start = -1, len = 0;

        for (i = 0; i < size2; ++i)
            index[s2[i]].push_back(i);
        for (i = 0; i < size1; ++i) {
            // char exists in s2
            if (!index[s1[i]].empty()) {
                for (j = 0; j < index[s1[i]].size(); ++j) {
                    l = index[s1[i]][j];
                    for (k = i; k < size1 && l < size2 && s1[k] == s2[l]; ++k, ++l)
                        ;
                    if (len < k-i) {
                        start = i;
                        len = k-i;
                    }
                }
            }
        }
        return len > 0 ? s1.substr(start, len) : "";
    }

    // Dynamic Programming
    // Reference: http://www.geeksforgeeks.org/longest-common-substring/
    string longestCommonSubstring_DP(string &s1, string &s2) {
        int size1 = s1.size(), size2 = s2.size();
        if (size1 == 0 || size2 == 0)
            return "";

        // lcsuff[i][j] contains longest common suffix length of 
        // s1[0...i-1] and s2[0...j-1]
        vector< vector<int> > lcsuff(size1+1, vector<int>(size2+1, 0));
        int i, j, len = 0, start = -1;

        for (i = 0; i < size1; ++i) {
            for (j = 0; j < size2; ++j) {
                // determine longest common suffix of s1[0...i] and s2[0...j],
                // then stored into lcsuff[i+1][j+1]
                if (s1[i] == s2[j]) {
                    lcsuff[i+1][j+1] = 1 + lcsuff[i][j];
                    if (lcsuff[i+1][j+1] > len) {
                        len = lcsuff[i+1][j+1];
                        start = i-len+1;
                    }
                }
            }
        }
        return len > 0 ? s1.substr(start, len) : "";
    }
};
int main(int argc, char *argv[])
{
    Solution sol;
    string s1 = "a";
    string s2 = "a";
    string result = sol.longestCommonSubstring(s1, s2);
    string result2 = sol.longestCommonSubstring_DP(s1, s2);
    cout << "---" << endl;
    cout << result << endl;
    cout << result2 << endl;
}