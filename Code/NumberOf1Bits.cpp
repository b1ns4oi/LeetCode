#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (; n; n >>= 1) {
        	if(n & 1 == 1) 
        		++ret;
        }
        return ret;
    }
};

int main()
{
	Solution s;
	unsigned n;
	std::cin >> n;
	std::cout << s.hammingWeight(n) << std::endl;
}