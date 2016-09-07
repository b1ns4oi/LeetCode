#include <iostream>

using namespace std;

class Solution {
public:
    // Attention that: sqrt(3) = 1, sqrt(2) = 1, sqrt(5) = 2...
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 1, r = x;
        int mid;

        while (l <= r) {    // must be "<=" rather than "<"
            mid = l + (r-l)/2;
            if (mid > x/mid)
                r = mid-1;
            else if (mid < x/mid)
                l = mid+1;
            else
                return mid;     // A
        }
        return r;   // if line A is not hit, 'r' should point to the right value
    }

    // Reference: https://discuss.leetcode.com/topic/8680/a-binary-search-solution/17
    int mySqrt2(int x) {
        if(x <= 1) return x;
        int left = 1, right = x;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(mid <= x / mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left-1;
    }
};

int main() 
{
    Solution sol;
    int ret = sol.mySqrt(19);
    int ret2 = sol.mySqrt2(19);
    cout << ret << endl;
    cout << ret2 << endl;
}
