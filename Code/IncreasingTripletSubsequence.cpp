#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty())
            return false;

        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end()) {
                v.push_back(nums[i]);
                if (v.size() == 3)
                    return true;
            }
            else
                *it = nums[i];
        }
        return false;
    }

    bool increasingTriplet_constant_space(vector<int>& nums) {
        int i, n1, n2;
        for (i = 0, n1 = n2 = INT_MAX; i < nums.size(); ++i) {
            if (nums[i] <= n1)
                n1 = nums[i];
            else if (nums[i] <= n2)
                n2 = nums[i];
            else
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    bool result = sol.increasingTriplet(nums);
    cout << result << endl;
}
