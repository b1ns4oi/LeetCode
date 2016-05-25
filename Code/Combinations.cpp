#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Reference: https://leetcode.com/discuss/32955/a-short-recursive-java-solution-based-on-c-n-k-c-n-1-k-1-c-n-1-k
    // C(n,k)=C(n-1,k-1)+C(n-1,k)
    vector<vector<int>> combine2(int n, int k) {
        // base condition
        if (k == 0 || n == k) {
            vector<int> v;
            for (int i = 1; i <= k; ++i)
                v.push_back(i);
            vector<vector<int> > vv;
            vv.push_back(v);
            return vv;
        }

        /*** Alternative way for base condition ***/
        // if (n < k) {
        //     return vector<vector<int> >();
        // }
        // if (k == 0) {
        //     return vector<vector<int> >(1, vector<int>());
        // }

        vector<vector<int> > sub1 = combine2(n-1, k-1);
        for (int i = 0; i < sub1.size(); ++i) {
            sub1[i].push_back(n);
        }
        vector<vector<int> > sub2 = combine2(n-1, k);
        sub1.insert(sub1.end(), sub2.begin(), sub2.end());

        return sub1;
    }
    
    // back-tracking
    vector<vector<int>> combine1(int n, int k) {
        vector<vector<int> > vv;
        vector<int> v;
        combine1(vv, v, n, k);
        return vv;
    }

private:
    void combine1(vector<vector<int> >& vv, vector<int>& v, int n, int k) {
        if (k == 0) {
            vv.push_back(v);
            return;
        }
        for (int i = n; i >= k; --i) {
            v.push_back(i);
            combine1(vv, v, i-1, k-1);
            v.pop_back();
        }

    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    // vector<int> nums = {10,1,2,7,6,1,5};
    // int target = 8;
    vector<vector<int>> result = sol.combine2(4, 2);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}