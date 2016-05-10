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

        // e.g. 1,5,6,4,3,2
        // 'i' will point to the index position of '5', elements between (i, n-1] are in descending order
        for (i = nums.size()-2; i >= 0 && nums[i] >= next; next = nums[i--])
            ;

        // 'nums' sorted reversely, we just sorted and return
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        // 'j-1' will point to the smallest element in (i, n-1] that is larger than 'nums[i]'
        for (j = i+1; j < nums.size() && nums[j] > nums[i]; ++j)
            ;

        // To accomplish the task, only two things need to be done:
        // 1, swap elements pointed by 'i' and 'j-1'
        // 2, sort elements between [i+1, n-1] into ascending order
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