#include <algorithm>
#include <vector>
#include <iostream>

using std::sort;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	// linear
    int findMin(vector<int> &num) {
    	int min = num[0];
        for(vector<int>::iterator it = num.begin(); it != num.end(); ++it) 
        	if(*it < min)
        		min = *it;
        return min;
    }

    // binary search
    int findMin_bs(vector<int> &num) {
    	vector<int>::iterator left, right, mid;
    	left = num.begin();
    	right = num.end() - 1;
    	while (left != right) {
    		mid = left + (right - left) / 2;
    		if     (*mid < *right) right = mid;
    		else if(*mid > *right) left = mid + 1;
    		else return -999; // invalid vector
    	}
    	return *left;
    }
};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(-2);
	vec.push_back(-1);
	vec.push_back(0);

	Solution sol;
	cout << sol.findMin_bs(vec) << endl;
}