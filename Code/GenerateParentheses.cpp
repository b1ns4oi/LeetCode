#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Reference: https://leetcode.com/discuss/14436/concise-recursive-c-solution
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generateParenthesis_recur(v, "", n, n);
        return v;
    }

private:
    void generateParenthesis_recur(vector<string>& v, string s, int left, int right) {
        if (left == 0 && right == 0) {
            v.push_back(s);
            return;
        }
        if (left > 0)
            generateParenthesis_recur(v, s+'(', left-1, right);
        if (right > left)
            generateParenthesis_recur(v, s+')', left, right-1);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> result = sol.generateParenthesis(4);
    for (string s : result)
        cout << s << endl;
    cout << result.size() << endl;
}