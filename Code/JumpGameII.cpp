#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Time Limit Exceeded
    int jump(vector<int>& nums) {
        return jump_recur(nums, 0);
    }

    // Unfortunately, still got 'Time Limit Exceeded' error.
    int jump_DP(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        v[n-1] = 0;  // initialize the last element

        for (int i = n-2; i >= 0; --i) {
            for (int j = 1; j <= nums[i] && j+i < n; ++j) {
                if (v[i+j] >= 0) {
                    if (v[i] == -1 || 1 + v[i+j] < v[i])
                        v[i] = 1 + v[i+j];
                }
            }
        }
        return v[0];
    }

    // Reference: https://discuss.leetcode.com/topic/18815/10-lines-c-16ms-python-bfs-solutions-with-explanations
    int jump3(vector<int>& nums) {
        int start = 0, end = 0, steps = 0;
        int n = nums.size();
        int max_end;

        while (end < n-1) {
            ++steps;
            max_end = end;
            for (int i = start; i <= end; ++i) {
                if (i+nums[i] > max_end) {
                    max_end = i+nums[i];                
                }
            }
            start = end+1;  
            end = max_end;
        }
        return steps;
    }

private:
    int jump_recur(vector<int>& nums, int start) {
        if (start >= nums.size()-1)
            return 0;

        int res = INT_MAX;
        int jmp;

        for (int i = 1; i <= nums[start]; ++i) {

            jmp = jump_recur(nums, start+i);
            if (jmp < res)
                res = jmp;
        }
        // Although we can assume that we can always reach the last index,
        // still should not just 'return 1 + res', take a look at this example: nums = {2,0,1}
        return res == INT_MAX ? res : 1 + res;
    }

};

int main() 
{
    Solution sol;
    vector<int> v = { 1,2,0,1 };
    int result = sol.jump3(v);
    cout << result << endl;
}