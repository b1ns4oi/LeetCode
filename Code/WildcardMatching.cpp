#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // will get "Time Limit Exceeded"
    bool isMatch(string s, string p) {
        string p2 = skip_consecutive_star(p);
        return isMatch_recur(s, s.size()-1, p2, p2.size()-1);
    }

    // Pass
    bool isMatch_DP(string s, string p) {
        p = skip_consecutive_star(p);
        int m = s.size(), n = p.size();

        vector<vector<bool> > v(m+1, vector<bool>(n+1, false));
        v[0][0] = true;
        int i, j;

        for (j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                v[0][j] = v[0][j-1];
            } 
        }
        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    v[i][j] = v[i-1][j] || v[i][j-1];
                }
                else if (p[j-1] == '?' || p[j-1] == s[i-1])
                    v[i][j] = v[i-1][j-1];
                else
                    ;
            }
        }
        return v[m][n];
    }

private:
    string skip_consecutive_star(const string& p) {
        string p2;
        char prev_char = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (prev_char == '*' && p[i] == '*')
                continue;
            p2 += p[i];
            prev_char = p[i];
        }
        return p2;
    }
    bool isMatch_recur(string &s, int i, string &p, int j) {
        if (j < 0) {
            return i < 0;
        }

        if (p[j] == '*') {
            // if (i >= 0) {
            //     return isMatch_recur(s, i-1, p, j) || isMatch_recur(s, i, p, j-1);
            // }
            // else
            //     return isMatch_recur(s, i, p, j-1);

            // Above if-else block can be simplified as:
            return isMatch_recur(s, i, p, j-1) || (i >= 0 && isMatch_recur(s, i-1, p, j));
        }
        else if (i >= 0 && (p[j] == '?' || p[j] == s[i])) {
            return isMatch_recur(s, i-1, p, j-1);
        }
        else
            return false;
    }
};


int main() {
    Solution sol;
    string s = "aa";
    string p = "*";
    bool result = sol.isMatch_DP(s, p);
    if (result)
      cout << "True" << endl;
    else
      cout << "False" <<endl;
}
