#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Solution {
public:
    bool isMatch(const char *s, const char *p)
    {
    	char *newp = filter_p(p);
        bool ret = helper(s, 0, newp, 0);
    	delete[] newp;
    	return ret;
    }
    
    // p[] contains only '*' in range [from...)
    bool onlystar(const char *p, size_t from)
    {
    	for(; p[from] != '\0'; ++from)
    		if(p[from] != '*')
    			return false;
    	return true;
    }

    //
    char *filter_p(const char *p) 
    {
    	vector<char> vec;
    	for(; *p; ++p) {
    		if(*p == '*') {
    			if(*(p+1) != '*')
    				vec.push_back(*p);
    		}	
    		else 
    			vec.push_back(*p);
    	}
    	vec.push_back('\0');
    	char *newp = new char[vec.size()];
    	for(int i = 0; i < vec.size(); ++i) {
    		newp[i] = vec[i];
    	}
    	return newp;
    }
    
    bool helper(const char *s, int indexs, const char *p, int indexp)
    {
    	if(indexs == strlen(s) && indexp == strlen(p))
    		return true;
    	if(indexs != strlen(s) && indexp == strlen(p))
    		return false;
        if(onlystar(p, indexp))
        	return true;
    	if(indexp != strlen(p) && indexs == strlen(s))
    		return false;
        
    	if(p[indexp] == '?' )
    		return helper(s, indexs+1, p, indexp+1);
    	else if(p[indexp] == '*') {
    		for(int i = 0; indexs+i <= strlen(s); ++i) {
    			if(helper(s, indexs+i, p, indexp+1))
                    return true;
    		}
            return false;
    	}
    	else
    		return s[indexs] == p[indexp] ? helper(s, indexs+1, p, indexp+1) : false;
    }
};

int main()
{
	
	const char *s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    const char *p = "a*******b";
    
    Solution sol;
    
    cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    
}
























