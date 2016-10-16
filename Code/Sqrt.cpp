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
    //
    // The code logic about adjusting the 'left' and 'right' pointers inside while loop is to make 
    // sure that if loop terminated, no matter whether we find the result exactly 
    // (if x is 4, for example, then result should be exactly 2), or just an approximate 
    // value (sqrt(3) == 1), final result should be just one "step" less than the 'left' pointer. 
    // Also notice that when loop terminated, 'left' must be equals to 'right'.
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
