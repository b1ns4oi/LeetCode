#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestPalindrome_eac(string s) {
    int s_len = s.size();
    if (s_len < 2)
        return 0;

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
        if (j == 0 && len < k-j+1) {
            len = k-j+1;
            start = j;
        }
    }
    return len;
}

class Solution {
public:
    string shortestPalindrome(string s) {
        if (is_palindrome(s)) {
            return s;
        }
        // get longest palindrome prefix substring with the help of longestPalindrome_eac()
        int len = longestPalindrome_eac(s);
        string rev(s.rbegin(), s.rbegin()+s.size()-len);
        return rev + s;
    }

    // implementation based on KMP algorithm
    // this implementation (of building KMP auxiliary table) is somehow straight-forward, and not efficiency
    // for better way, refer to: https://web.stanford.edu/class/cs97si/10-string-algorithms.pdf
    string shortestPalindrome_KMP(const string& s) {
        int len = 0;
        string rev(s.rbegin(), s.rend());
        for (int i = 1; i <= s.size(); ++i) {
            string left = s.substr(0, i);
            string right = rev.substr(rev.size() - i, i);
            if (left == right)
              len = i;
        }
        cout << len << endl;
        return string(s.rbegin(), s.rbegin()+s.size()-len) + s;
    }


private:
    bool is_palindrome(const string& s) {
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-i-1])
                return false;
        }
        return true;
    }
};

int main() {
	 Solution sol;
   string s = "abcd";
   string result = sol.shortestPalindrome(s);
   string result2 = sol.shortestPalindrome_KMP(s);
   cout << result << endl;
   cout << result2 << endl;
}