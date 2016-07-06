#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // iterative solution, will get "Time Limit Exceeded" error
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;

        unordered_set<int> st;
        int target = nums.size()-1;

        st.insert(0);
        while (!st.empty()) {
            int idx = *st.begin();
            st.erase(st.begin());
            if (idx == target)
                return true;
            for (int i = 1; i <= nums[idx]; ++i) {
                if (idx+i > target)
                    continue;  // for this problem, we can also return 'true' here
                st.insert(idx+i);
            }
        }
        return false;
    }

    // recursive solution, will also get "Time Limit Exceeded" error
    bool canJump2(vector<int>& nums) {
        if (nums.empty())
            return false;
        return canJump_recur(nums, 0, nums.size()-1);
    }

    // recursive solution, cache the result
    // unfortunately, still got "Time Limit Exceeded"
    bool canJump3(vector<int>& nums) {
        if (nums.empty())
            return false;

        // '0' for unknown status
        // '1' for false
        // '2' for true
        vector<int> result(nums.size(), 0);

        return canJump_recur3(nums, 0, nums.size()-1, result);
    }

    // This solution iterate from end to start.
    // For each index 'i' ('i' start at nums.size()-2), if it can reach the 'target', then we treat it as the new 'target';
    // if not, just continue to check the previous index. 
    //
    // Attention that with either condition, we make the problem's size one index less, thus it'll eventually get solved.
    //
    // Time complexity: O(n)
    // Space complexity: O(1)
    bool canJump4(vector<int>& nums) {
        int target = nums.size()-1;

        for (int i = target-1; i >= 0; --i) {
            if (nums[i]+i >= target)
                target = i;
        }
        return target == 0;
    }

private:
    bool canJump_recur(vector<int>& nums, int start, int target) {
        if (start == target)
            return true;

        for (int i = 1; i <= nums[start]; ++i) {
            if (canJump_recur(nums, start+i, target))
                return true;
        }
        return false;
    }

    bool canJump_recur3(vector<int>& nums, int start, int target, vector<int>& result) {
        if (result[start] != 0)
            return result[start] == 1 ? false : true;

        if (start == target) {
            result[start] = 2;
            return true;
        }

        for (int i = 1; i <= nums[start]; ++i) {
            if (canJump_recur3(nums, start+i, target, result)) {
                result[start+i] = 2;
                return true;
            }
            else
                result[start+i] = 1;
        }
        result[start] = 1;
        return false;
    }
};


int main() 
{
    Solution sol;

    vector<int> v = { 2,3,1,1,4 };
    bool result = sol.canJump4(v);

    cout << result << endl;
}