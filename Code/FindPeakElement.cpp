#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        long prev = LONG_MIN;
        int i;
        for (i = 0; i < nums.size()-1; prev = nums[i++]) {
            if (nums[i] > prev && nums[i] > nums[i+1])
                return i;
        }
        return (nums[i] > prev) ? i : -1;
    }

    // binary search
    int findPeakElement_bsearch(vector<int>& nums) {
        return search(nums, 0, nums.size()-1);
    }

private:
    int search(vector<int>& nums, int i, int j) {
        if (i == j)
            return i;
        int mid = (i+j)/2;
        if (nums[mid] < nums[mid+1])
            return search(nums, mid+1, j);
        else
            return search(nums, i, mid);
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v{1,2,3};
    int result = sol.findPeakElement(v);
    int result2 = sol.findPeakElement_bsearch(v);
    cout << result << endl;
    cout << result2 << endl;
}
