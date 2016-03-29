#include <iterator>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        char c;
        while(n) {
        	n--;
        	c = 'A' + n%26;
        	ret = c + ret;
        	n /= 26;
        }
        return ret;
    }
};

int main()
{
	Solution s;
	cout << s.convertToTitle(26*28)<< endl;
}