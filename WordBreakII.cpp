#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_set>
#include <algorithm>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::copy;
using std::unordered_set;
using std::ostream_iterator;
using std::map;

class Solution {
public:
    vector<vector<string> > wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
		string s1;
		map<int, vector<vector<string> > > result;
		vector<vector<string> > s2  = helper(s, s1, dict, 0, result);
		
		return s2;
		//return ret;
    }
	
	// void helper(vector<string>& ret, const string& s, string& s1, const unordered_set<string>& dict, int start, map<int, vector<vector<string> > >& result)
	// {
		// if(start == s.size()) {
			// ret.push_back(s1);
			// return;
		// }
		// string subs;
		// for(int i = start; i < s.size(); ++i) {
			// subs = s.substr(start, i-start+1);
			// if(dict.find(subs) != dict.end()) {
				//append the candidate to s1
				// s1.append(" ");
				// s1.append(subs);
				//deal with the sub-problem
				// helper(ret, s, s1, dict, i+1, result);
				//undo the append operation(i.e. erase subs)
				// s1.erase(s1.end()-subs.size()-1, s1.end());
			// }
		// }
	// }
	
	vector<vector<string> > helper( const string& s, 
									string& s1, 
									const unordered_set<string>& dict, 
									int start, 
									map<int, vector<vector<string> > >& result)
	{
		vector<vector<string> > ret;
		if(start == s.size()) {
			result[start] = ret;
			return ret;
		}
		if(result.find(start) != result.end()) {
			return result[start];
		}
		
		
		for(int i = start; i < s.size(); ++i) {
			string subs = s.substr(start, i-start+1);
			if(dict.find(subs) != dict.end()) {
				// vector<string> member;
				// member.push_back(subs);
				ret = helper(s, s1, dict, i+1, result);
				
				for(int i = 0; i < ret.size(); ++i) {
					ret[i].push_back(subs);
				}
			}
		}
		result[start] = ret;
		return ret;
	}
};

int main()
{
	string s = "catcatsand";
	unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//unordered_set<string> dict({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
	
	Solution sol;
	vector<vector<string> > ret = sol.wordBreak(s, dict);
	for(int i = 0; i < ret.size(); ++i) {
		copy(ret[i].begin(), ret[i].end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
	
	cout << endl;
}













