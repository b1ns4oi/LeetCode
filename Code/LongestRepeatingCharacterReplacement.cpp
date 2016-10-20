#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i, j, l, len, max_occur = 0, res = 0;
        int n = s.size();
        vector<int> v(26, 0);

        for (i = j = 0; j < n; ++j) {
        	max_occur = std::max(++v[s[j]-'A'], max_occur);
        	while (j-i+1-max_occur > k) {
        		if (max_occur == v[s[i++]-'A']--)
        			--max_occur;
        		for (l = 0; l < 26; ++l)
        			if (max_occur < v[l])
        				max_occur = v[l];
        	}
        	res = std::max(res, j-i+1);
        }
        return res;
    }
};

int main() {
	Solution sol;
	string s = "AABABBA";
	cout << sol.characterReplacement(s, 2) << endl;; 
}
