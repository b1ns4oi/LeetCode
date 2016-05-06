#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size()-1;

        while (i <= j) {
            int h = min(height[i], height[j]);
            water = max(water, (j-i)*h);
            while (height[i] <= h && i <= j) ++i;
            while (height[j] <= h && i <= j) --j;
        }
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {2,2,3};
    int result = sol.maxArea(height);
    cout << result << endl;
}