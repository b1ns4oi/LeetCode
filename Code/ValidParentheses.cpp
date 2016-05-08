#include <iostream>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> m = { {'(', ')'}, {'{', '}'}, {'[', ']'}, {')', '('}, {'}', '{'}, {']', '['} };
        stack<char> stk;

        for (auto c : s) {
            if (m.count(c) > 0) {
                if (c == '}' || c == ']' || c == ')') {
                    if (stk.empty() || stk.top() != m[c])
                        return false;
                    stk.pop();
                }
                else {
                    stk.push(c);
                }
            }
        }
        return stk.empty();
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s(argv[1]);
    bool result = sol.isValid(s);
    cout << result << endl;
}
