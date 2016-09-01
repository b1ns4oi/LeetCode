#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // recursive solution
    // "Time Limit Exceeded"
    // time complexity: O(2^(m+n))
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }

    // DP
    // time complexity: O(m*n)
    int uniquePaths2(int m, int n) {
        vector<vector<int> > vec(m+1, vector<int>(n+1));   // a structure to store uniquePaths result of grid
        int i, j;

        // initialization
        for (i = 0; i <= m; ++i)
            vec[i][1] = 1;
        for (j = 0; j <= n; ++j)
            vec[1][j] = 1;

        // bottom-up traversal
        for (i = 2; i <= m; ++i)
            for (j = 2; j <= n; ++j)
                vec[i][j] = vec[i-1][j] + vec[i][j-1];

        return vec[m][n];
    }
};

int main() 
{
    Solution sol;
    int ret1 = sol.uniquePaths(23, 12);
    int ret2 = sol.uniquePaths2(23, 12);
    cout << ret1 << endl;
    cout << ret2 << endl;
}
