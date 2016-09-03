#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // DP solution
    // time complexity: O(m*n)
    // space complexity: O(m*n)
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

    // DP solution without space
    // During DP traversal, using original structure 'obstacleGrid' to store result
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int i, j;

        if (obstacleGrid[m-1][n-1])
            return 0;
        obstacleGrid[m-1][n-1] = 1;

        for (i = m-2; i >= 0; --i)
            obstacleGrid[i][n-1] = (!obstacleGrid[i+1][n-1] || obstacleGrid[i][n-1]) ? 0 : 1;
        for (j = n-2; j >= 0; --j) {
            obstacleGrid[m-1][j] = (!obstacleGrid[m-1][j+1] || obstacleGrid[m-1][j]) ? 0 : 1;
            for (i = m-2; i >= 0; --i) {
                if (!obstacleGrid[i][j])    // no obstacle at this point
                    obstacleGrid[i][j] = obstacleGrid[i+1][j] + obstacleGrid[i][j+1];
                else
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid[0][0];
    }
};

int main() 
{
    vector<vector<int> > obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};

    Solution sol;
    int ret1 = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << ret1 << endl;
}
