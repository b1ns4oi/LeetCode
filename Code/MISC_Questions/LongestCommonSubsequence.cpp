// Reference: http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
//
// Given two strings, return the length of the longest common sub-sequences of them.
// Example:
// LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
// LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestCommonSubsquence_Recur_Helper(string&, string&, int, int);

// Top-down recursive solution
// Time complexity: O(2^n)
int longestCommonSubsquence_Recur(string& s1, string& s2) {
    if (s1.empty() || s2.empty())
        return 0;
    return longestCommonSubsquence_Recur_Helper(s1, s2, s1.size()-1, s2.size()-1);
}

int longestCommonSubsquence_Recur_Helper(string& s1, string& s2, int i, int j) {
    if (i < 0 || j < 0)
        return 0;

    if (s1[i] == s2[j]) {
        return 1+longestCommonSubsquence_Recur_Helper(s1, s2, i-1, j-1);
    }
    else
        return max(
            longestCommonSubsquence_Recur_Helper(s1, s2, i, j-1),
            longestCommonSubsquence_Recur_Helper(s1, s2, i-1, j));
}

// Bottom-up dynamic-programming solution
// Time complexity: O(m*n)
int longestCommonSubsquence_DP(string& s1, string& s2) {
    if (s1.empty() || s2.empty())
        return 0;

    int m = s1.size(), n = s2.size();
    vector<vector<int> > v(m, vector<int>(n, 0));

    // initialize first row and column
    for (int i = 0; i < m; ++i) {
        if (s2[0] == s1[i])
            while (i < m)
                v[i++][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (s2[i] == s1[0])
            while (i < n)
                v[0][i++] = 1;
    }

    // DP iteration
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (s1[i] == s2[j])
                v[i][j] = 1+v[i-1][j-1];
            else {
                v[i][j] = max(v[i][j-1], v[i-1][j]);
            }
        }
    }
    return v[m-1][n-1];
}

int main(int argc, char *argv[])
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    int result1 = longestCommonSubsquence_DP(s1, s2);
    int result2 = longestCommonSubsquence_Recur(s1, s2);
    cout << result1 << endl;
    cout << result2 << endl;
}