#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        unordered_map<int, int> m;
        int i, left, right, len = 0, sum;
        for (i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i]) > 0)
                continue;

            left = m.count(nums[i]-1) ? m[nums[i]-1] : 0;
            right = m.count(nums[i]+1) ? m[nums[i]+1] : 0;
            // cout <<left << " - " << right << endl;

            sum = left+right+1;
            len = max(len, sum);

            // set max value for boundary elements
            if (m.count(nums[i]-left))
                m[nums[i]-left] = sum;
            if (m.count(nums[i]+right))
                m[nums[i]+right] = sum;

            m[nums[i]] = sum;
        }
        return len;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {100,99};
    int result = sol.longestConsecutive(nums);
    cout << "---" << endl;
    cout << result << endl;
}
