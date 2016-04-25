#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // #16
    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k;
        int n = nums.size();
        int sum;

        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else if (n == 2) return nums[0] + nums[1];

        std::sort(nums.begin(), nums.end());

        sum = nums[0] + nums[1] + nums[2];
        for (i = 0; i < n-2; ++i) {
        	for (j = i+1, k = n-1; j < k;) {
        		int sum_local = nums[j] + nums[k];
        		if (abs(target - nums[i] - sum_local) < abs(target - sum)) {

        			// this if block is optional
        			if (nums[i] + sum_local == target)
        				return target;

        			sum = nums[i] + sum_local;
        		}
        		(nums[i] + sum_local < target) ? ++j : --k;
        	}
        }
        return sum;
    }

    // #15
    vector<vector<int> > threeSum(vector<int>& nums) {
        int i, j, k;
        int n = nums.size();
        int sum;
        vector<vector<int> > ret;

        if (n < 3)
            return ret;
        std::sort(nums.begin(), nums.end());

        for (i = 0; i < n-2; ++i) {
            for (j = i+1, k = n-1; j < k;) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    ret.push_back(triplet);
                    while (j < k && nums[j] == triplet[1]) ++j;
                    while (j < k && nums[k] == triplet[2]) --k;
                }
                else
                    (nums[i] + nums[j] + nums[k] > 0) ? --k : ++j;
            }
            while (i+1 < n-2 && nums[i+1] == nums[i])
                ++i;
        }
        return ret;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {1,2,4,8,16,32,64,128};
	int result = sol.threeSumClosest(nums, 82);
	cout << "-------------------- \n" << result << endl;
}
