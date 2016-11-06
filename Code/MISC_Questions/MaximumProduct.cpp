// 给一个无序数组，元素都为正整数，现在要找出其中两个元素，使得二者的积最大，并且寻找两个因数过程必须保证：
// 1，两个因数中，第一个小于第二个
// 2，第一个因数出现在第二个前面
// 给定的数组保证有解
// e.g.  
// [4,2,3,7] --> 28([4,7])
// [2,8,9,9] --> 72([8,9])
// [3,5,4]   --> 15([3,5])
//
// 注意：这一题和Leetcode 的 #152. Maximum Product Subarray 不一样 (https://leetcode.com/problems/maximum-product-subarray/)
//
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;


int MaximumProduct(vector<int> input) {
	int i, j, res = INT_MIN, flr;

	for (i = 1; i < input.size(); ++i) {
		if (input[i] < input[i-1])
			continue;
		flr = INT_MIN;
		for (j = 0; j < i; ++j) {
			if (input[j] < input[i] && input[j] > flr)
				flr = input[j];
		}
		if (flr != INT_MIN)
			res = std::max(res, flr*input[i]);
	}
	return res;
}

// O(n)
int MaximumProduct2(vector<int> input) {

	int max_i, max_j, res = INT_MIN;
	int i, j, k, start, end;

	// During each iteration, find the max element, store its index at 'k'
	// now MaximumProduct of sub-array input[0] to input[k] should be 'max_j * input[k]' where
	// 'max_j' is the max element of sub-array input[0...k-1]
	// So we're done with input[0] -- input[k]
	//
	// Then just work on input's next half (input[k+1 ... n])
	//
	// Overall complexity should be O(n)
	//
	for (start = 0, end = input.size(); start < end; start = k+1) {
		max_i = max_j = INT_MIN;
		for (i = start; i < end; ++i)
			if (input[i] > max_i) {
				max_i = input[i];
				k = i;
			}

		for (j = start; j < k; ++j) {
			if (input[j] > max_j) {
				max_j = input[j];
			}
		}
		if (max_j != INT_MIN)
			res = std::max(res, max_j * max_i);
	}
	return res;

}

int main() {
	vector<int> int_array = {4,2,3,7,10, 9, 8, 6, 20, 7, 84, 8, 1,2,3,4,9};  // 2,8,9,9
	int res = MaximumProduct(int_array);
	int res2 = MaximumProduct2(int_array);
	cout << res << endl;
	cout << res2 << endl;
}

