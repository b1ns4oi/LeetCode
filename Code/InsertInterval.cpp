#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i, j;
        bool flag = true;  // indicate whether 'newInterval' will be the first element in 'intervals'
        vector<Interval> ret;

        // insert 'newInterval' into 'intervals'
        vector<Interval>::iterator it = lower_bound(intervals.begin(), intervals.end(), newInterval, comp_f);
        it = intervals.insert(it, newInterval);

        // merge from position pointed by 'it-1' (if 'it' is not the first element) 
        // or 'it' (if it is the first element)
        i = it - intervals.begin();
        if (i > 0) {
            --i;
            flag = false;            
        }

        // copy element before 'i' into 'ret'
        copy(intervals.begin(), intervals.begin()+i, back_inserter(ret));

        // merge
        for (j = i; j < intervals.size()-1; ++j) {
            if (intervals[j].end >= intervals[j+1].start) {
                intervals[j+1].start = intervals[j].start;
                intervals[j+1].end = max(intervals[j].end, intervals[j+1].end);
            }
            // still need to continue trying to merge 'newInterval' and its following element
            else if (!flag && j == i)
                ret.push_back(intervals[j]);
            else
                break;  // we are done
        }

        // copy all left elements
        copy(intervals.begin()+j, intervals.end(), back_inserter(ret));

        return ret;
    }
};

int main() 
{
    Solution sol;
    vector<Interval> vec = {};
    Interval newInterval(2,3);

    vector<Interval> ret = sol.insert(vec, newInterval);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i].start << " - " << ret[i].end << endl;
    }
}