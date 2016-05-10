#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;

        int next = nums.back();
        int i, j;

        for (i = nums.size()-2; i >= 0 && nums[i] >= next; next = nums[i--])
            ;

        // sorted 
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        for (j = i+1; j < nums.size() && nums[j] > nums[i]; ++j)
            ;

        iter_swap(nums.begin()+i, nums.begin()+j-1);
        for (i += 1, j = nums.size()-1; i < j; ++i, --j) {
            iter_swap(nums.begin()+i, nums.begin()+j);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = {1,5,6,4,3,2};
    sol.nextPermutation(v);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}