#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int i, j, min_len = INT_MAX, sum = 0;
        for (i = 0, j = 0; j < nums.size(); ++j) {
            sum += nums[j];

            while (sum >= s) {
                if (min_len > j-i+1)
                    min_len = j-i+1;
                sum -= nums[i++];
            }
        }
        return min_len != INT_MAX ? min_len : 0;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int s = 7;
    std::vector<int> nums = {2,3,1,2,4};
    int result = sol.minSubArrayLen(s, nums);
    cout << result << endl;
}
