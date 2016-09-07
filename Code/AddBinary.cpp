#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // my ugly version, not concise
    string addBinary(string a, string b) {
        string::reverse_iterator it1, it2;
        string ret;
        int additional_bit = 0;

        for (it1 = a.rbegin(), it2 = b.rbegin(); it1 != a.rend() && it2 != b.rend(); ++it1, ++it2) {
            int sum = (*it1-'0') + (*it2-'0') + additional_bit;
            additional_bit = 0;     // clear
            if (sum == 1 || sum == 3)
                ret.push_back('1');
            else
                ret.push_back('0');

            if (sum > 1)    // reset addtional_bit
                additional_bit = 1;
        }

        if (it1 != a.rend())
            for (; it1 != a.rend(); ++it1) {
                int sum = (*it1-'0') + additional_bit;
                additional_bit = 0;
                if (sum == 1)
                    ret.push_back('1');
                else
                    ret.push_back('0');

                if (sum == 2)
                    additional_bit = 1;
            }

        if (it2 != b.rend()) {

            for (; it2 != b.rend(); ++it2) {
                int sum = (*it2-'0') + additional_bit;
                additional_bit = 0;
                if (sum == 1)
                    ret.push_back('1');
                else
                    ret.push_back('0');

                if (sum == 2)
                    additional_bit = 1;
            }
        }
            

        if (additional_bit == 1)
            ret.push_back('1');

        reverse(ret.begin(), ret.end());
        return ret;
    }

    // concise code
    // Reference: https://discuss.leetcode.com/topic/8981/short-code-by-c
    string addBinary2(string a, string b) {
        int sum = 0;
        int i = a.size()-1, j = b.size()-1;
        string ret;

        for (; i >= 0 || j >= 0 || sum == 1; ) {
            sum += (i >= 0 ? a[i--]-'0' : 0);
            sum += (j >= 0 ? b[j--]-'0' : 0);
            ret.push_back(sum%2 + '0');
            sum /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() 
{
    Solution sol;
    string a = "1010";
    string b = "1011";

    string ret = sol.addBinary(a, b);
    string ret2 = sol.addBinary2(a, b);

    cout << ret << endl;
    cout << ret2 << endl;
}
