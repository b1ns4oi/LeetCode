#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_left = 0, max_right = 0;
        int res = 0;

        while (i < j) {
            if (height[i] < height[j]) {
                if (height[i] < max_left)
                    res += max_left - height[i];
                else
                    max_left = height[i];
                ++i;
            }
            else {
                if (height[j] < max_right)
                    res += max_right - height[j];
                else
                    max_right = height[j];
                --j;
            }
        }
        return res;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {4,0,4};
    int result = sol.trap(nums);
    cout << result << endl;
}