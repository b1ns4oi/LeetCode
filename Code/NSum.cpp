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

    // #1
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> nums_copy = nums;
        int n = nums_copy.size();
        vector<int> ret;

        std::sort(nums_copy.begin(), nums_copy.end());
        for (i = 0, j = n-1; i < j; ) {
            if (nums_copy[i] + nums_copy[j] == target) {
                ret.push_back(find(nums.begin(), nums.end(), nums_copy[i]) - nums.begin());
                ret.push_back(n - 1 - (find(nums.rbegin(), nums.rend(), nums_copy[j]) - nums.rbegin()));
                return ret;
            }
            else
                (nums_copy[i] + nums_copy[j] > target) ? --j : ++i;
        }
        return ret;
    }
    // #1 hash
    vector<int> twoSum_hash(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ret;

        for (int i = 0; i < nums.size(); ++i) {
            int num_to_find = target - nums[i];
            if (m.count(num_to_find) > 0) {
                ret.push_back(i);
                ret.push_back(m[num_to_find]);
                // "You may assume that each input would have exactly one solution."
                return ret;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {3,2,4};
	vector<int> result = sol.twoSum(nums, 6);
	cout << "-------------------- \n" << endl;
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
