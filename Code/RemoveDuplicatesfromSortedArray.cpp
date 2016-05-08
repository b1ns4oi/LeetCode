#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        int i, j, e;

        /*
        ** Loop invariant: [0, i] contains the non-duplicated elements.
        */
        for (i = 0, j = 1, e = nums[0]; j < nums.size(); ++j) {
            if (nums[j] != e) {
                e = nums[j];
                int t = nums[++i]; 
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        return i+1;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = {1,2};
    int result = sol.removeDuplicates(v);
    cout << result << endl;

    for (int i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";
    cout << endl;
}