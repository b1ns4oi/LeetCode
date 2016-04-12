#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    // refer to: http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
    int lengthOfLIS_DP(vector<int>& nums) {
        int len = 0;
        if (nums.empty())
            return len;

        int i, j, k;
        vector<int> v(nums.size(), 1);
        for (i = 0; i < nums.size(); ++i) {
            for (j = k = 0; j < i; ++j) {
                if (nums[j] < nums[i] && k < v[j]+1)
                    k = v[j] + 1;
            }
            if (k > 0)
                v[i] = k;
        }
        vector<int>::iterator len_it = max_element(v.begin(), v.end());
        return *len_it;
    }

    // This solution is described at https://leetcode.com/discuss/67554/9-lines-c-code-with-o-nlogn-complexity
    // which is pretty cool
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end())
                v.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return v.size();
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int result = sol.lengthOfLIS(nums);
    cout << result << endl;
}
