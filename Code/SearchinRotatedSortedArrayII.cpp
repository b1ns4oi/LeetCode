#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Reference: https://leetcode.com/discuss/223/when-there-are-duplicates-the-worst-case-is-could-we-do-better
    // answered by user "1337c0d3r"
    bool search(vector<int>& nums, int target) {
        int i, j;

        for (i = 0, j = nums.size()-1; i <= j; ) {
            int mid = (i+j)/2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] > nums[i]) {
                if (nums[i] <= target && target < nums[mid])
                    j = mid-1;
                else
                    i = mid+1;
            }
            else if (nums[mid] < nums[i]) {
                if (nums[mid] < target && target <= nums[j])
                    i = mid+1;
                else
                    j = mid-1;
            }
            else
                ++i;
        }        
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {1,1,2,1};
    int result1 = sol.search(nums, stoi(argv[1]));
    cout << result1 << endl;
}