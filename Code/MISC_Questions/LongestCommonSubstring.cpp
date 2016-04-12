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

        vector<int> index(128, -1);
        int i, j, k, start = 0, len = 0;

        for (i = 0; i < size2; ++i)
            index[s2[i]] = i;
        for (i = 0; i < size1; ++i) {
            // char exists in s2
            if ((j = index[s1[i]]) > -1) {
                for (k = i; k < size1 && j < size2 && s1[k] == s2[j]; ++k, ++j)
                    ;
                if (len < k-i) {
                    start = i;
                    len = k-i;
                }
            }
        }

        return len > 0 ? s1.substr(start, len) : "";
    }
};
int main(int argc, char *argv[])
{
    Solution sol;
    string s1 = "aaaa";
    string s2 = "a";
    string result = sol.longestCommonSubstring(s1, s2);
    cout << "---" << endl;
    cout << result << endl;
}
