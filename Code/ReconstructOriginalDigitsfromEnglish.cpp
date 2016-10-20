#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	// error: Time Limit Exceeded
    string originalDigits(string s) {
        map<char, int> m;
        vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        string res;
        int i;

        for (i = 0; i < s.size(); ++i)
        	++m[s[i]];

        if (originalDigits_recur(m, words, 0, res))
        	return res;
        else {
        	cout << "error input..." << endl;
        	return "";
        }
    }

    // work-around
    // O(n)
    string originalDigits2(string s) {
        map<char, int> m;
        vector<int> v(10, 0);
        vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        vector<char> chars = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 's', 'i'};
        vector<int> orders = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    	int i, j;
    	string res;

    	for (i = 0; i < s.size(); ++i)
    		++m[s[i]];

		for (i = 0; i < orders.size(); ++i) {
			while (m[chars[i]] > 0) {
				for (j = 0; j < words[orders[i]].size(); ++j)
					--m[words[orders[i]][j]];
				++v[orders[i]];
			}
		}

		for (i = 0; i < v.size(); ++i)
			res += string(v[i], '0'+i);
		return res;
    }

private:
	bool originalDigits_recur(map<char, int>& m, vector<string>& words, int from, string& res) {
		int i, j, k;
		if (m.empty())
			return true;
		if (from >= words.size())
			return false;

		for (i = from; i < words.size(); ++i) {
			for (j = 0; j < words[i].size(); ++j) {
				if (m.count(words[i][j]) == 0 || m[words[i][j]] == 0)
					break;
			}
			// matched
			if (j == words[i].size()) {
				// adjust m
				for (k = 0; k < words[i].size(); ++k) {
					if (--m[words[i][k]] == 0)
						m.erase(words[i][k]);
				}
				res += i+'0';

				if (originalDigits_recur(m, words, i, res))
					return true;
				else {
					for (k = 0; k < words[i].size(); ++k) {
						++m[words[i][k]];
					}
					res.pop_back();
				}
			}
		}
		return false;
	}

};

int main() {
	Solution sol;
	string s = "one";
	cout << sol.originalDigits(s) << endl;; 
	cout << sol.originalDigits2(s) << endl;; 
}