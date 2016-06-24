// 215. Kth Largest Element in an Array

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
    // time complexity: O(n * logk)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.begin()+k);

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    // time complexity: O(n) on average
    int findKthLargest_2(vector<int>& nums, int k) {
        int n = nums.size();
        int p;
        int i, j;

        for (i = 0, j = n-1; (p = partition(nums, i, j)) != n-k; ) {
            if (n-p > k)
                i = p+1;
            else
                j = p-1;
        }
        return nums[p];
        // return partition(nums, 0, n-1);
    }

private:
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[l];
        int j = l;

        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < pivot) {
                ++j;
                iter_swap(nums.begin()+i, nums.begin()+j);
            }
        }
        iter_swap(nums.begin()+l, nums.begin()+j);
        return j;
    }
};

int main(int argc, char *argv[]) 
{
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};

    int result = sol.findKthLargest_2(nums, 2);
    cout << result << endl;

}
