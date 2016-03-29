
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::cout;
using std::endl;

class Solution {
public:
    int maxProduct(int A[], int n) {
    	if (n <= 0)
    		return 0;
    	if (n == 1 && A[0] <= 0)
    		return A[0];

    	vector<int> zero;
    	for (int i = 0; i != n; ++i)
        	if (A[i] == 0)
        		zero.push_back(i);

        int ret = 0, k = -1;
        for(int i = 0; i != zero.size(); k = zero[i++]) {
        	ret = max(ret, maxProductWithoutZero(A+k+1, zero[i]-k-1));
        }
        ret = max(ret, maxProductWithoutZero(A+k+1, n-k-1));
        return ret;
    }

private:
	int maxProductWithoutZero(int A[], int n) {
    	if (n <= 0)
    		return 0;
    	if (n == 1 && A[0] <= 0)
    		return A[0];

        vector<int> aux;
      	for (int i = 0; i != n; ++i)
        	if (A[i] < 0)
        		aux.push_back(i);

        // no negative elements or the number of negatives is even
        if (aux.size() == 0 || (aux.size() & 1) == 0) {
        	return productInRange(A, A+n);
        } 
       	else if (aux.size() == 1)
       		return max(productInRange(A, A+aux[0]), productInRange(A+aux[0]+1, A+n));
       	else 
       		return max(productInRange(A, A+aux[aux.size() - 1]), productInRange(A+aux[0]+1, A+n));
       
    }

	int productInRange(int *p1, int *p2) {
		if (p1 == p2)
			return 0;
		int product = 1;
		for (; p1 != p2; ++p1)
			product *= *p1;
		return product;
	}
};

int main()
{
	int arr[7] = {1,0,-1,2,3,-5,-2};
	Solution sol;
	cout << sol.maxProduct(arr, 7) << endl;
}






