#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vv;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combinationSum_helper(vv, v, candidates, target, 0);

        return vv;
    }

private:
    void combinationSum_helper(
        vector<vector<int>>& vv, 
        vector<int>& v, 
        vector<int>& candidates,
        int target, 
        int i) {

        if (target == 0) {
            vv.push_back(v);
            return;
        }
        for (; i < candidates.size() && candidates[i] <= target; ++i) {
            v.push_back(candidates[i]);
            combinationSum_helper(vv, v, candidates, target-candidates[i], i);
            v.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {1,2,3,6,7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(nums, target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}