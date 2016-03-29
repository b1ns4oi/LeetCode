#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include <iterator>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void split(vector<string> &tokens, const string &text, char sep) {
  	int start = 0, end = 0;
  	while ((end = text.find(sep, start)) != string::npos) {
    	tokens.push_back(text.substr(start, end - start));
    	start = end + 1;
  	}
  	tokens.push_back(text.substr(start));
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
    	vector<string> s1, s2;
    	split(s1, version1, '.');
    	split(s2, version2, '.');

    	vector<string>& less_s = s1.size() > s2.size() ? s2 : s1;
    	int n = s1.size() - s2.size();
    	if(less_s == s1) 
    		n *= -1;
    	while(n--) 
    		less_s.push_back("0");
    	
    	int ret;
    	for(int i = 0; i < s1.size(); ++i) 
    		if((ret = ver_cmp(s1[i], s2[i])) != 0)
    			return ret;
    	return 0;
    }
private:
	int ver_cmp(const string &s1, const string &s2) {
		int n1 = atoi(s1.c_str());
		int n2 = atoi(s2.c_str());
		return (n1 > n2) ? 1 : ((n1 == n2) ? 0 : -1);
	}
};

int main()
{
	string s1 = "01";
	string s2 = "1";
	Solution s;
	cout << s.compareVersion(s1, s2) << endl;
}







