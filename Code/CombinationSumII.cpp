#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        for (int j = i; j < candidates.size() && candidates[j] <= target; ++j)
            // take care of duplicate combinations
            // since 'candidates' has been sorted, all the duplicated elements will be gathered together
            if (j == i || candidates[j] != candidates[j-1]) {
                v.push_back(candidates[j]);
                combinationSum_helper(vv, v, candidates, target-candidates[j], j+1);
                v.pop_back();
            }
        
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(nums, target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}