#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_set>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::copy;
using std::unordered_set;


class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int result[s.size()];
		for(int i = 0; i < s.size(); ++i)
			result[i] = -1;
			
        return helper(s, 0, dict, result);
    }
	
	bool helper(const string& s, int start, unordered_set<string>& dict, int *result)
	{
		if(start == s.size())
			return true;
		if(result[start] > -1)
			return result[start];
		for(int i = start; i < s.size(); ++i) {
			if(dict.find(s.substr(start, i-start+1)) != dict.end() && helper(s, i+1, dict, result)) {
				result[start] = 1;
				return true;
			}	
		}
		return (result[start] = 0);
	}
};

int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	unordered_set<string> dict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});

	Solution sol;
	cout << sol.wordBreak(s, dict) << endl;
}





















































