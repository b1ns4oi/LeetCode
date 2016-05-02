#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        map<int, int> m;
        for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
            if (m.count(*it) > 0)
                ++m[*it];
            else
                m[*it] = 1;
        }

        vector<pair<int, int> > v(m.begin(), m.end());
        sort(v.begin(), v.end(), compare);

        vector<int> ret(k);
        for (int i = 0; i < k; ++i)
            ret[i] = v[i].first;
        return ret;
    }
};

int main() {
	 Solution sol;
   int k = 2;
   vector<int> result = sol.topKFrequent(vector<int>{1,2,3}, k);
   for (int i = 0; i < k; ++i) {
        cout << result[i] << " ";
   }
   cout << endl;
}












