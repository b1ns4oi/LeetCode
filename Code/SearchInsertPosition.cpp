#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1, mid;

        while (i <= j) {
            mid = (i+j)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        // 1, we can infer that at this point, i == j+1
        // 2, after each iteration, 'i' denotes that all elements (if any) before 'i' is less than 'target'
        // 3, after each iteration, 'j' denotes that all elements (if any) after 'j' is greater than 'target'
        // 4, combined with 1, we can infer that if 'target' should be inserted after 'j', which is exactly 'i'
        return i;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {1,3,5,6};
    int result1 = sol.searchInsert(nums, stoi(argv[1]));
    cout << result1 << endl;
}