class Solution {
public:
    // Hint: 
    // There is a simple O(n) solution to this problem.
    // You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
    int integerBreak(int n) {
        // special case when n = 2 or 3
        if (n <= 3)
            return n-1;

        int n_3 = n/3;
        int ret = 1;

        if (n%3 == 1) {
            --n_3;
            ret *= 4;
        }
        else if (n%3 == 2) {
            ret *= 2;
        }
        else
            ;

        while (n_3--)
            ret *= 3;
        return ret;
    }
};