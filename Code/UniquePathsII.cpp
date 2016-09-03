#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int i, j;
        vector<vector<int> > vec(m+1, vector<int>(n+1, 0));   // store result

        // initialization
        for (i = m-1; i >= 0; --i) {
            for (j = n-1; j >= 0; --j) {
                if (i == m-1 && j == n-1 && !obstacleGrid[i][j])
                    vec[i][j] = 1;
                else
                    vec[i][j] = obstacleGrid[i][j] ? 0 : vec[i+1][j] + vec[i][j+1];
            }
        }
        return vec[0][0];
    }
};

int main() 
{
    vector<vector<int> > obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};

    Solution sol;
    int ret1 = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << ret1 << endl;
}
