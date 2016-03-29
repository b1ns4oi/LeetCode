#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	// binary search
    int findMin(vector<int> &num) {
    	vector<int>::iterator left, right, mid;
    	left = num.begin();
    	right = num.end() - 1;
    	while (left != right) {
    		mid = left + (right - left) / 2;
    		if      (*mid > *right) left = mid+1;
    		else if (*mid < *right) right = mid;
    		else --right;
    	}
    	return *left;
    }
};

int main()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);

	Solution sol;
	cout << sol.findMin(vec) << endl;
}
