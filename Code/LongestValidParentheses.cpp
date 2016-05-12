#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // one-pass scan
    // Reference: https://leetcode.com/discuss/7609/my-o-n-solution-using-a-stack
    int longestValidParentheses(string s) {
        stack<int> stk;
        int longest = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stk.push(i);
            else {
                if (!stk.empty() && s[stk.top()] == '(')
                    stk.pop();
                else
                    stk.push(i);
            }
        }
        // Now stack only contains indices of characters that can't be matched
        // what we need to do is to calculate the interval length between those indices
        if (stk.empty())
            return s.size();

        int a = s.size(), b = 0;
        while (!stk.empty()) {
            b = stk.top();
            stk.pop();
            longest = max(longest, a-b-1);
            a = b;
        }
        longest = max(longest, a);
        return longest;
    }

    // DP solution
    // Reference: https://leetcode.com/discuss/8092/my-dp-o-n-solution-without-using-stack
    int longestValidParentheses_DP(string s) {
        int n = s.size();
        int i, longest = 0;
        vector<int> v(n+1, 0);

        for (i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    v[i+1] = v[i-1] + 2;
                }
                else if (i-v[i]-1 >= 0 && s[i-v[i]-1] == '(') {
                    v[i+1] = v[i] + 2 + v[i-v[i]-1];
                }
                else
                    ;
                longest = max(longest, v[i+1]);
            }
        }
        return longest;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s = "()";
    int result1 = sol.longestValidParentheses(s);
    int result2 = sol.longestValidParentheses_DP(s);
    cout << result1 << endl;
    cout << result2 << endl;
}