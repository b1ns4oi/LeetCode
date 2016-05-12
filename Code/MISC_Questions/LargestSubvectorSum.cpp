/* Problem defined in <Programming Pearls> Chapter 8
** Given a vector of integers, find a contiguous sub-vector with the largest sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP solution
int largestSubvectorSum_DP(vector<int>& nums) {
    vector<int> v(nums.size()+1, 0);

    for (int i = 0; i < nums.size(); ++i)
        v[i+1] = max(nums[i] + v[i], 0);
    return *max_element(v.begin(), v.end());
}

// Divided-Conquer
int largestSubvectorSum_DC_recur(vector<int>& nums, int l, int r) {
    if (l > r) // empty
        return 0;
    if (l == r) // one element
        return max(nums[l], 0);

    int m = (l+r)/2;
    int sum = 0, max_l = 0, max_r = 0;

    for (int i = m; i >= l; --i) {
        sum += nums[i];
        max_l = max(max_l, sum);
    }
    sum = 0;
    for (int i = m+1; i <= r; ++i) {
        sum += nums[i];
        max_r = max(max_r, sum);
    }
    return max(
        max_l + max_r,
        max(largestSubvectorSum_DC_recur(nums, l, m), largestSubvectorSum_DC_recur(nums, m+1, r)));
}
int largestSubvectorSum_DC(vector<int>& nums) {
    return largestSubvectorSum_DC_recur(nums, 0, nums.size()-1);
}


int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3, -10, 5, 6};
    int result1 = largestSubvectorSum_DP(nums);
    int result2 = largestSubvectorSum_DC(nums);
    cout << result1 << endl;
    cout << result2 << endl;
}