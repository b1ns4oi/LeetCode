#include <iostream>
#include <string>
#include <climits>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, start = 0;
        if (s.size() == 0) 
            return len;

        int i = 0, j = 0;
        vector<int> v(128, 0);
        // copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        for (; j < s.size(); ++j) {
            if (v[s[j]]++ > 0) {
                for (; s[i] != s[j]; ++i)
                    --v[s[i]];
                --v[s[i++]];
            }
            else if (j-i+1 > len) {
                len = j-i+1;
                start = i;
            }
        }
        if (len)
            cout << s.substr(start, len) << endl;
        return len;
    }

    
};

int main()
{
    Solution sol;
    cout << sol.lengthOfLongestSubstring("aaaaaa") << endl;
}

