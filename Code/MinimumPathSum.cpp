#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // recursive solution
    // "Time Limit Exceeded" error
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSum_recur(grid, 0, 0);
    }

    // DP solution
    // time complexity: O(m*n)
    int minPathSum2(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int i, j;
        vector<vector<int> > vec(m+1, vector<int>(n+1, INT_MAX));

        for (i = m-1; i >= 0; --i) {
            for (j = n-1; j >= 0; --j) {
                if (i == m-1 && j == n-1)
                    vec[i][j] = grid[i][j];
                else
                    vec[i][j] = grid[i][j] + min(vec[i+1][j], vec[i][j+1]);
            }
        }
        return vec[0][0];
    }
private:
    int minPathSum_recur(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();

        if (r == m || c == n)
            return INT_MAX;
        if (r == m-1 && c == n-1)
            return grid[r][c];

        int sum_right = minPathSum_recur(grid, r, c+1);
        int sum_bottom = minPathSum_recur(grid, r+1, c);

        return grid[r][c] + min(sum_right, sum_bottom);
    }
};

int main() 
{
    vector<vector<int> > obstacleGrid = {
        {7,1,3,5,8,9,9,2,1,9,0,8,3,1,6,6,9,5},
        {9,5,9,4,0,4,8,8,9,5,7,3,6,6,6,9,1,6},
        {8,2,9,1,3,1,9,7,2,5,3,1,2,4,8,2,8,8},
        {6,7,9,8,4,8,3,0,4,0,9,6,6,0,0,5,1,4},
        {7,1,3,1,8,8,3,1,2,1,5,0,2,1,9,1,1,4},
        {9,5,4,3,5,6,1,3,6,4,9,7,0,8,0,3,9,9},
        {1,4,2,5,8,7,7,0,0,7,1,2,1,2,7,7,7,4},
        {3,9,7,9,5,8,9,5,6,9,8,8,0,1,4,2,8,2},
        {1,5,2,2,2,5,6,3,9,3,1,7,9,6,8,6,8,3},
        {5,7,8,3,8,8,3,9,9,8,1,9,2,5,4,7,7,7},
        {2,3,2,4,8,5,1,7,2,9,5,2,4,2,9,2,8,7},
        {0,1,6,1,1,0,0,6,5,4,3,4,3,7,9,6,1,9}
    };

    Solution sol;
    int ret1 = sol.minPathSum(obstacleGrid);
    int ret2 = sol.minPathSum2(obstacleGrid);
    cout << ret1 << endl;
    cout << ret2 << endl;
}
