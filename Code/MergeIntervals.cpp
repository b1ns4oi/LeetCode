#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp_f(const Interval& i1, const Interval& i2) {
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2)
            return intervals;

        // sort intervals by 'start' field
        sort(intervals.begin(), intervals.end(), comp_f);

        int i, j;
        vector<Interval> ret;

        for (i = 0; i < intervals.size()-1; ++i) {
            // try to merge intervals[i] and intervals[i+1]
            // if they can't be merged, means the first element can't be merged by any element left
            // just save it
            if (intervals[i+1].start > intervals[i].end)
                ret.push_back(intervals[i]);

            // else merge them and continue
            else {
                intervals[i+1].start = intervals[i].start;
                intervals[i+1].end = max(intervals[i].end, intervals[i+1].end);
            }
        }
        ret.push_back(intervals[i]);
        return ret;
    }
};

int main() 
{
    Solution sol;
    vector<Interval> vec = {{15, 18}, {8, 10}, {1,3}, {2,6}, {2,7}};

    vector<Interval> ret = sol.merge(vec);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i].start << " - " << ret[i].end << endl;
    }
}