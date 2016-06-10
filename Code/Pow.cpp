#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	// Time Limit Exceeded
    double myPow(double x, int n) {
        double res = 1.0;
        bool sign = false;

        if (n < 0) {
            n *= -1;
            sign = true;
        }

        while (n--) {
            res *= x;
        }
        return sign ? 1/res : res;
    }

    // Reference: https://leetcode.com/discuss/17005/short-and-easy-to-understand-solution
    double myPow_2(double x, int n) {
    	if (n == 0)
    		return 1;

    	// there's a boundary case which makes n as "INT_MIN", then n *= -1 will get overflow
    	// so convert to long integer type to solve this problem
    	long ln = n;

    	if (ln < 0) {
    		ln *= -1;
    		x = 1/x;
    	}

    	return ln % 2 == 0 ? myPow(x*x, ln/2) : x * myPow(x*x, ln/2);
    }
};