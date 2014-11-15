#include <iostream>
#include <string>
#include <vector>
#include <iterator>
//#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::copy;
//using std::unordered_set;
using std::ostream_iterator;
using std::map;
using std::set;

class Solution {
public:
    vector<string> wordBreak(string s, set<string> &dict) {
        vector<string> ret;
		string s1;
		map<int, vector<vector<string> > > result;
		vector<vector<string> > s2  = helper(s, dict, 0, result);
		
        for(int i = (int)s2.size()-1; i >= 0; --i) {
            string s;
            for(int j = (int)s2[i].size()-1; j >= 0; --j) {
                if(j < s2[i].size()-1)
                    s.append(" ");
                s.append(s2[i][j]);
            }
            ret.push_back(s);
        }
        
		return ret;
    }
	
	vector<vector<string> > helper( const string& s,
                                   const set<string>& dict,
                                   int start,
                                   map<int, vector<vector<string> > >& result)
	{
        // find cache if that result exists already
		if(result.find(start) != result.end()) {
			return result[start];
		}
        
		vector<vector<string> > ret;
		if(start == s.size()) {
            // add one empty element to ret
            vector<string> item;
            ret.push_back(item);
            // save the result as cache
			result[start] = ret;
			return ret;
		}
		
		for(int i = start; i < s.size(); ++i) {
			string subs = s.substr(start, i-start+1);
			if(dict.find(subs) != dict.end()) {
				vector<vector<string> > subret = helper(s, dict, i+1, result);                
				for(int j = 0; j < subret.size(); ++j) {
					subret[j].push_back(subs);
                    ret.push_back(subret[j]);
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
	set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	
}













