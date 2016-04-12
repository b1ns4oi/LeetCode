#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long ret = 0;
        while (x) {
            ret = ret*10 + x%10;
            x /= 10;
        }
        return (ret < INT_MIN || ret > INT_MAX ) ? 0 : ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int x = -123;
    int result = sol.reverse(x);
    cout << "---" << endl;
    cout << result << endl;
}
