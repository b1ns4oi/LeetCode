#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // My own solution for this question.
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        res[0] = n;
        search(nums, target, 0, n-1, res);
        if (res[0] == n)
            res[0] = -1;
        return res;
    }

    // This idea is straightforward: 
    // 1, search the first occurance of 'target'
    // 2, search the last occurance of 'target'
    // 3, construct result based on step 1/2
    // Reference: https://leetcode.com/discuss/18242/clean-iterative-solution-binary-searches-with-explanation
    vector<int> searchRange2(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        int mid;
        vector<int> res(2, -1);

        // search for first occurance
        while (i < j) {
            mid = (i+j)/2;
            if (nums[mid] < target)
                i = mid+1;
            else
                j = mid;
        }
        if (nums[i] != target)
            return res;
        res[0] = i;

        // search for last occurance (no need to adjust 'i')
        j = nums.size()-1;
        while (i < j) {
            // pay attention here, the '+1' is to make sure i-j boundary to shrink in case of two element left
            mid = (i+j + 1) / 2;
            if (nums[mid] > target)
                j = mid-1;
            else
                i = mid;
        }
        res[1] = i;
        return res;
    }

private:
    void search(vector<int>& nums, int target, int i, int j, vector<int>& res) {
        if (i > j)
            return;

        int mid = (i+j)/2;
        if (nums[mid] == target) {
            if (mid < res[0]) {
                res[0] = mid;
            }
            if (mid > res[1]) {
                res[1] = mid;
            }
            search(nums, target, i, mid-1, res);
            search(nums, target, mid+1, j, res);
        }
        else if (nums[mid] < target)
            search(nums, target, mid+1, j, res);
        else
            search(nums, target, i, mid-1, res);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {1,1,1,1,1,1,1,2};
    vector<int> result1 = sol.searchRange2(nums, stoi(argv[1]));
    for (auto i : result1) {
        cout << i << " ";
    }
    cout << endl;
}