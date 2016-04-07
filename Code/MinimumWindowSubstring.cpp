#include <iostream>
#include <string>
#include <climits>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string ret = "";
        int t_len = t.size();
        if (s.size() == 0 || t_len == 0 || t_len > s.size())
            return ret;

        map<char, int> m;
        for (auto c : t) 
            ++m[c];

        int start = 0, end = 0, counter = t_len, min_len = INT_MAX, min_start = 0;
        for (; end < s.size(); ++end) {
            // char exists in t
            if (m[s[end]] > 0) {
                --counter;
            }
            --m[s[end]]; 

            // window found
            while (counter == 0) {
                if (end-start+1 < min_len) {
                    min_len = end-start+1;
                    min_start = start;
                }

                if (m[s[start]] == 0) {
                    ++counter;
                }
                ++m[s[start]];
                ++start;
            }
        }
        if (min_len < INT_MAX)
            ret = s.substr(min_start, min_len);
        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.minWindow("a", "aa") << endl;
}

