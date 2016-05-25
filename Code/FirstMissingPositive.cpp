#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Reference: https://leetcode.com/discuss/24013/my-short-c-solution-o-1-space-and-o-n-time
    //
    // 1, This algorithm puts each number in the right index (i.e. make sure nums[i] == i)
    //    and it does a minor improvement to make use of the index 0 to save space
    // 2, iterate over the newly generated array, first missing positive number must be the one
    //    which is not equal to its index
    int firstMissingPositive(vector<int>& nums) {
        int i, n = nums.size();

        for (i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i]-1 < n && nums[nums[i]-1] != nums[i]) {
                // swap
                int t = nums[i];
                nums[i] = nums[t-1];
                nums[t-1] = t;
            }
        }

        for (i = 0; i < n; ++i)
            if (nums[i] != i+1)
                break;
        return i+1;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {4};
    int result = sol.firstMissingPositive(nums);
    cout << result << endl;
}