#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // This solution is based on a set structure to ensure that only distinct element will be swapped
    // and thus make sure result is unique
    vector<vector<int>> permuteUnique1(vector<int>& nums) {
        vector<vector<int>> res;

        if (!nums.empty())
            permuteUnique1(nums, 0, res);
        return res;
    }

    // Reference: https://leetcode.com/discuss/25279/a-simple-c-solution-in-only-20-lines
    //
    // 1, sort the vector
    // 2, make the swap without back-tracking after recursive call
    vector<vector<int>> permuteUnique2(vector<int>& nums) {
        vector<vector<int>> res;

        if (!nums.empty()) {
            sort(nums.begin(), nums.end());
            permuteUnique2(nums, 0, res);
        }
        return res;
    }
private:
    void permuteUnique1(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        set<int> st;
        for (int j = i; j < nums.size(); ++j) {
            // only swap distinct element
            if (st.find(nums[j]) == st.end()) {
                st.insert(nums[j]);
                iter_swap(nums.begin()+i, nums.begin()+j);
                permuteUnique1(nums, i+1, res);
                iter_swap(nums.begin()+i, nums.begin()+j);
            }
        }
    }

    // Pay attention that here 'nums' is not passed as a reference!
    void permuteUnique2(vector<int> nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            // only swap distinct element
            if (i == j || nums[j] != nums[i]) {
                iter_swap(nums.begin()+i, nums.begin()+j);
                permuteUnique2(nums, i+1, res);
            }
        }
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = sol.permuteUnique2(nums);
    
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}