#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	//save bits(reversed) into array
    	unsigned char bits[32];
    	for(int i = 0; i < 32; ++i, n >>= 1) 
    		bits[i] = (n & 1) ? 1 : 0;
    	//construct return value based on array
    	//loop invariant:
    	//pre: 0 to (i-1)th bits were constructed
    	//post: ith bit was constructed 
    	uint32_t ret = 0;
    	for(int i = 0; i < 32; ++i) {
    		ret <<= 1; 
    		if(bits[i])
    			ret |= 0x00000001;
    	}
        return ret;
    }
};

int main()
{
	unsigned char a = 0x01;
	unsigned char b = 0xff;
	std::cout << (a ^ b) << std::endl;
	Solution s;
	std::cout << s.reverseBits(43261596) << std::endl;
}