#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            s = f(s);
        }
        return s;
    }

    string countAndSay_recur(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay_recur(n-1);
        return f(s);
    }
private:
    // count-and-say the string 'n', return the result
    string f(string& n) {
        string res;

        for (int i = 0; i < n.size(); ) {
            int times = 1;
            char c = n[i];
            for (++i; i < n.size() && n[i] == c; ++i)
                ++times;

            res += times+'0';
            res += c;
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string result = sol.countAndSay_recur(stoi(argv[1]));
    cout << result << endl;
}