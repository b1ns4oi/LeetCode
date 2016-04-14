#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // recursive version
    // this one will not get passed due to "time limit exceeded"
    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();

        if (l1 == 0 || l2 == 0 || l2 > l1)
            return 0;  

        if (l2 == 1) {
            int count = std::count(s.begin(), s.end(), t[0]);
            return count;
        }

        int ret = 0;
        for (int i = 0; i < l1; ++i) {
            if (s[i] == t[0]) {
                ret += numDistinct(s.substr(i+1), t.substr(1));
            }
        }
        return ret;
    }

    // DP version
    // reference: https://leetcode.com/discuss/2143/any-better-solution-that-takes-less-than-space-while-in-time
    int numDistinct_DP(string s, string t) {
        if (s.empty())
            return t.empty() ? 1 : 0;
        if (t.empty())
            return 1;

        vector<vector<int> > table(t.size(), vector<int>(s.size(), 0));
        // initialize
        if (s[0] == t[0])
            table[0][0] = 1;
        for (int i = 1; i < s.size(); ++i)
            table[0][i] = table[0][i-1] + (s[i] == t[0] ? 1 : 0);

        // construct
        for (int i = 1; i < t.size(); ++i) {
            for (int j = 1; j < s.size(); ++j) {
                table[i][j] = table[i][j-1] + (s[j] == t[i] ? table[i-1][j-1] : 0);
            }
        }
        return table[t.size()-1][s.size()-1];
    }

};


int main(int argc, char *argv[])
{
    Solution sol;
    string t = "bddabdcae";
    string s = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
    int result = sol.numDistinct_DP(s, t);
    int result2 = sol.numDistinct(s, t);
    cout << endl << "-----------" << endl;
    cout << result << endl;
    cout << result2 << endl;
}
