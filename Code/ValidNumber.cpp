#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    // Difficulty of this problem is: there's so much edge cases to handle (partially because of the 
    // ambiguous statement of the problem), it's hard to come up with a consistent way to deal with 
    // that much edge cases.
    //
    // Reference: https://discuss.leetcode.com/topic/9490/clear-java-solution-with-ifs
    bool isNumber(string s) {
        int i, j, k, n = s.size();
        bool num_seen = false, point_seen = false, e_seen = false, number_after_e = true;

        // trim leading and trailing space
        for (i = 0; i < n && isspace(s[i]); ++i)
            ;
        for (j = n-1; j >= 0 && isspace(s[j]); --j)
            ;

        // now [i, j] should be the result string
        for (k = i; k <= j; ++k) {
            if (isdigit(s[k])) {
                num_seen = true;
                if (!number_after_e)
                    number_after_e = true;            
            }
            else if (s[k] == '.') {
                if (point_seen || e_seen)   return false;
                point_seen = true;
            }
            else if (s[k] == 'e') {
                if (e_seen || !num_seen)    return false;
                e_seen = true;
                number_after_e = false;
            }
            else if (s[k] == '+' || s[k] == '-') {
                if (k != i && s[k-1] != 'e')    return false;
            }
            else 
                return false;
        }
        return num_seen && number_after_e;
    }
};

int main() 
{
    Solution sol;
    string s = "  1 4 ";

    bool ret = sol.isNumber(s);

    string ret_s;
    ret_s = ret ? "true" : "false";
    cout << ret_s << endl;
    cout << endl;
 
}
