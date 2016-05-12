#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Linear scan
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    // Divide-Conquer
    int search2(vector<int>& nums, int target) {
        int i, j;
        int n = nums.size();

        for (i = 0, j = n-1; i <= j; ) {
            int mid = (i+j)/2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] >= nums[i]) {
                if (target > nums[mid]) {
                    i = mid+1;
                }
                else {
                    int r1 = binary_search(nums, target, i, mid-1);
                    if (r1 > -1)
                        return r1;
                    i = mid+1;
                }
            }
            else {
                if (target > nums[mid]) {
                    int r1 = binary_search(nums, target, mid+1, j);
                    if (r1 > -1)
                        return r1;
                    j = mid-1;
                }
                else {
                    j = mid-1;
                }
            }
        }
        return -1;
    }

    // Binary-Search Solution
    // Reference: https://leetcode.com/discuss/11701/concise-o-log-n-binary-search-solution
    // This idea is really brilliant!
    int search3(vector<int>& nums, int target) {
        int rot;
        int n = nums.size();
        int i = 0, j = n-1, mid;

        // find smallest element
        while (i < j) {
            mid = (i+j)/2;
            if (nums[mid] > nums[j])
                i = mid+1;
            else
                j = mid;
        }
        rot = i;

        // do binary search
        for (i = 0, j = n-1; i <= j; ) {
            mid = (i+j) / 2;
            int realmid = (rot+mid) % n;
            if (nums[realmid] == target)
                return realmid;
            else if (nums[realmid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        return -1;
    }

private:
    int binary_search(vector<int>& sorted_nums, int target, int left, int right) {
        int i = left, j = right;
        int mid;

        while (i <= j) {
            mid = (i+j)/2;
            if (sorted_nums[mid] == target)
                return mid;
            else if (sorted_nums[mid] > target)
                j = mid-1;
            else
                i = mid+1;
        }
        return -1;
    }

};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {4,5,6,7,8,0,1,2,3};
    int result1 = sol.search(nums, stoi(argv[1]));
    int result2 = sol.search2(nums, stoi(argv[1]));
    cout << result1 << endl;
    cout << result2 << endl;
}