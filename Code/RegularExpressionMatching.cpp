#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch_recur(s, s.size()-1, p, p.size()-1);
    }

    bool isMatch_DP(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<bool> > v(s.size()+1, vector<bool>(p.size()+1, false));
        // empty "s" matches empty "p" 
        v[0][0] = true;

        int i, j;
        for (j = 1; j <= n; ++j) {
            if (p[j-1] == '*')
                v[0][j] = v[0][j-2];
        }

        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    if (p[j-2] == '.' || p[j-2] == s[i-1])
                        // strictly speaking, "|| v[i-1][j-2]" is redundant
                        v[i][j] = (v[i-1][j] || v[i-1][j-2] || v[i][j-2]);
                    else
                        v[i][j] = v[i][j-2];
                }
                else if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    v[i][j] = v[i-1][j-1];
                }
                else
                    ;  // Since all elements have already been initialized to "false", no need to do assignment again.
            }
        }
        return v[m][n];
    }

private:
    bool isMatch_recur(string& s, int i, string& p, int j) {
        if (j < 0) {
            return i < 0 ? true : false;
        }
        if (p[j] == '*') {
            if (i >= 0 && (p[j-1] == '.' || p[j-1] == s[i])) {
                if (isMatch_recur(s, i-1, p, j))
                    return true;
                else if (isMatch_recur(s, i-1, p, j-2))
                    return true;
                else
                    return isMatch_recur(s, i, p, j-2);
            }
            else 
                return isMatch_recur(s, i, p, j-2);
        }
        else if (i >= 0 && (p[j] == s[i] || p[j] == '.'))
            return isMatch_recur(s, i-1, p, j-1);
        else
            return false;
    }


};

int main() {
    Solution sol;
    string s = "aa";
    string p = "a";
    bool result = sol.isMatch(s, p);
    bool result2 = sol.isMatch_DP(s, p);
    if (result)
      cout << "True" << endl;
    else
      cout << "False" <<endl;
    cout << " ------ " << endl;

    if (result2)
       cout << "True" << endl;
    else
       cout << "False" <<endl;

}
