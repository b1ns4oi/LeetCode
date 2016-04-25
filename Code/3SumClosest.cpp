#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
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
};

int main() {
	Solution sol;
	vector<int> nums = {1,2,4,8,16,32,64,128};
	int result = sol.threeSumClosest(nums, 82);
	cout << "-------------------- \n" << result << endl;
}