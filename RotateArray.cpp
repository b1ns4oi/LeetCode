#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
    	if(n <= 0 || k < 0)
    		return;
        vector<int> rightk;
        int k1 = k%n;
        int i;
        for(i = n-k1; i < n; ++i)
        	rightk.push_back(nums[i]);
        //shift 0th-(n-k1-1)th elements to right
        for(i = n-k1-1; i >= 0; --i) 
        	nums[i+k1] = nums[i];
        //copy the last k1 elements into nums
        for(i = 0; i < rightk.size(); ++i)
        	nums[i] = rightk[i];
    }
};

int main()
{
	Solution s;
	int k;
	cin >> k;
	int nums[] = {1, 2, 3, 4,  5, 6, 7};
	s.rotate(nums, 7, k);
	copy(nums, nums+7, ostream_iterator<int>(cout, " "));
	cout << endl;
}