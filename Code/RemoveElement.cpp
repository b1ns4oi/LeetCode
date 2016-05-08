#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j;
        /*
        ** Loop invariant: [0, i] contains the result elements which not equal to 'val' so far.
        ** before loop: (i, j) contains element equal to 'val'.
        */
        for (i = -1, j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
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
    vector<int> v = {1,2,2,2,2,2, 3, 4};
    int result = sol.removeElement(v, 2);
    cout << result << endl;

    for (int i = 0; i < v.size(); ++i) 
        cout << v[i] << " ";
    cout << endl;
}