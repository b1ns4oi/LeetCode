#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int j = s.size()-1;
        int ret = 0;

        int prev = -1;
        for (; j >= 0; --j) {
            if (m[s[j]] >= prev)
                ret += m[s[j]];
            else
                ret -= m[s[j]];
            prev = m[s[j]];
        }
        return ret;
    }

private:
    map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; 
};

int main(int argc, char *argv[]) {
    Solution sol;
    int result = sol.romanToInt(argv[1]);
    cout << result << endl;
}
