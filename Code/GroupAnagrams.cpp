#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// 1, maintain a map, with key be the each sorted element in 'strs', 
	//    value be the index of all anagrams of the key in 'res'
	// 2, for each element in 'strs', first check if its sorted version exists in map, 
	//    if it does, just insert into the related entry; else build a new entry dedicated for this anagram, save index in map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;

        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
        	string s = *it;
        	sort(s.begin(), s.end());
        	if (m.count(s) > 0) {
        		res[m[s]].push_back(*it);
        	}
        	else {
        		m[s] = res.size();
        		vector<string> sub_v(1, *it);
        		res.push_back(sub_v);
        	}
        }

        return res;
    }
};

int main() 
{
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat", "abt"};

	Solution sol;
	vector<vector<string>> res = sol.groupAnagrams(strs);

	int len = res.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}