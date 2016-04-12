#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int len = 0, i, j, k = x;
        while (k) {
            ++len;
            k /= 10;
        }
        for (k = x; len > 1; k /= 10, len -= 2) {
            i = k/pow(10, len-1);
            k %= int(pow(10, len-1));
            j = k%10;
            if (i != j)
                return false;
        }
        return true;
    }
};
int main(int argc, char *argv[])
{
    Solution sol;
    int x = -2147447412;
    bool result = sol.isPalindrome(x);
    cout << "---" << endl;
    cout << result << endl;
}
