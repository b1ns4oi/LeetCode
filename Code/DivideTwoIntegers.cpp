#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    // Reference: https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        bool sign = ((dividend < 0) ^ (divisor < 0)) ? true : false;
        long long dvd = dividend;
        long long dvs = divisor;
        if (dvd < 0) dvd *= -1;
        if (dvs < 0) dvs *= -1;

        int res = 0;
        while (dvd >= dvs) {
            long long tmp = dvs;
            int times = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                times <<= 1;
            }
            dvd -= tmp;
            res += times;
        }
        return sign ? -res : res;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int result = sol.divide(stoi(argv[1]), stoi(argv[2]));
    cout << result << endl;
}