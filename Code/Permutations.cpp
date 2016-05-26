#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        if (!nums.empty())
            permute(nums, 0, res);
        return res;
    }

private:
    void permute(vector<int>& nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;            
        }
        for (int j = i; j < nums.size(); ++j) {
            iter_swap(nums.begin()+i, nums.begin()+j);
            permute(nums, i+1, res);
            iter_swap(nums.begin()+i, nums.begin()+j);
        }
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {1,2};
    vector<vector<int>> result = sol.permute(nums);
    
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}