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
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s = argv[1];
    string result = sol.longestPalindrome(s);
    cout << result << endl;
}

