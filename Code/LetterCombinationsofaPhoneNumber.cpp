#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        for (int i = 0; i < digits.size(); ++i) {
            int n = digits[i] - '0';
            v.push_back(table[n]);
        }
        return f(v, 0, v.size()-1);
    }

private:
    vector<string> table = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> f(vector<string>& v, int i, int j) {
        vector<string> ret;
        if (i > j)
            ;
        else if (i == j) {
            for (auto c : v[i])
                ret.push_back(string(1, c));
        }
        else {
            vector<string> sub_ret = f(v, i+1, j);
            for (auto c : v[i]) {
                for (auto s : sub_ret) {
                    ret.push_back(c + s);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    vector<string> result = sol.letterCombinations(argv[1]);
    for (auto s : result) {
        cout << s << " ";
    }
    cout << endl;
}