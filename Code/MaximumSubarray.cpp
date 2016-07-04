#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> v(nums.size()+1, 0);
        int res = INT_MIN;
        
        for (int i = 1; i <= nums.size(); ++i) {
            if (v[i-1] >= 0)
                v[i] = nums[i-1] + v[i-1];
            else
                v[i] = nums[i-1];
            
            if (v[i] > res)
                res = v[i];
        }
        return res;
    }
};

int main() 
{
    Solution sol;
    vector<int> nums = {-1};
    int result = sol.maxSubArray(nums);

    cout << result << endl;
}