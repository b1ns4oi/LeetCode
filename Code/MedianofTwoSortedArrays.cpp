#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double med = 0.0;
        vector<int> combine;
        int i, j, size = nums1.size() + nums2.size();
        for (i = j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] < nums2[j])
                combine.push_back(nums1[i++]);
            else
                combine.push_back(nums2[j++]);

        }
        if (i < nums1.size())
            combine.insert(combine.end(), nums1.begin()+i, nums1.end());
        if (j < nums2.size())
            combine.insert(combine.end(), nums2.begin()+j, nums2.end());

        if (size & 1)
            med = combine[size/2];
        else
            med = (combine[size/2] + combine[size/2 - 1])/2.0;
        return med;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<int> nums1 = {1,2,3,6};
    std::vector<int> nums2 = {0,4,5};
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << "---" << endl;
    cout << result << endl;
}
