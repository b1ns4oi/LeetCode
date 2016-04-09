// Discussion:
// https://leetcode.com/articles/longest-palindromic-substring/#approach-1-longest-common-substring-accepted
// http://articles.leetcode.com/longest-palindromic-substring-part-i/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;


class Solution {
public:
    // Expand Around Center
    // Time:  O(n^2)
    // Space: O(1)
    string longestPalindrome(string s) {
        int s_len = s.size();
        if (s_len < 2)
            return s;

        int i, j, k, start = 0, len = 1;
        for (i = 0; i < s_len && (s_len-i) > len/2;) {
            j = k = i;
            while (k < s_len-1 && s[k+1] == s[k])
                ++k;
            i = k + 1;
            while (k < s_len-1 && j > 0 && s[k+1] == s[j-1]) {
                ++k;
                --j;
            }
            if (len < k-j+1) {
                len = k-j+1;
                start = j;
            }
        }
        string sub = s.substr(start, len);
        return sub;
    }

    // DP solution
    // Time:  O(n^2)
    // Space: O(n^2)
    string longestPalindrome_DP(string s) {
        int s_len = s.size();
        if (s_len < 2)
            return s;

        bool table[1000][1000] = {false};
        int len; // substring length
        int i, start = 0, palin_len = 1;

        for (i = 0; i < s_len; ++i)
            table[i][i] = true;
        for (i = 0; i < s_len-1; ++i) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                start = i;
                palin_len = 2;
            }
        }

        for (len = 3; len <= s_len; ++len) {
            for (i = 0; i <= s_len-len; ++i) {
                if (s[i] == s[i+len-1] && table[i+1][i+len-2]) {
                    table[i][i+len-1] = true;
                    start = i;
                    palin_len = len;
                }
            }
        }
        return s.substr(start, palin_len);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s = argv[1];
    string result = sol.longestPalindrome(s);
    cout << result << endl;
}

