#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;


class Solution {
public:
    // brute force
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > v;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && is_panlindrome(words[i] + words[j])) {
                    v.push_back(vector<int>{i, j});
                }
            }
        }
        return v;
    }

    /*
    ** Algorithm based on hash has time complexity O(m * n^2), which m is size of "words", n is average size of each word
    **
    ** Pay attention to boundary cases when "left" or "right" is empty sub-string
    ** We can avoid these duplicate result by using a "set" as a workaround, for details, check "palindromePairs_hash2()"
    */
    vector<vector<int> > palindromePairs_hash(vector<string>& words) {
        vector<vector<int> > ret;
        map<string, int> m;
        int i, j;

        // build map with reverse word as key, index as value
        for (i = 0; i < words.size(); ++i)
            m[string(words[i].rbegin(), words[i].rend())] = i;

        // because of "j < words[i].size()" in next for loops, need to take care this special case
        // ["aba", ""]
        if (m.count("") > 0) {
            for (j = 0; j < words.size(); ++j) {
                if (words[j] == "")
                    continue;
                if (is_panlindrome(words[j]))
                    ret.push_back(vector<int>{m[""], j});
            }
        }

        for (i = 0; i < words.size(); ++i) {
            for (j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);

                if (is_panlindrome(left) && m.count(right) > 0 && m[right] != i)
                    ret.push_back(vector<int>{m[right], i});
                if (is_panlindrome(right) && m.count(left) > 0)
                    ret.push_back(vector<int>{i, m[left]});
            }
        }
        return ret;
    }

    // Using a "set" structure to avoid duplicates
    vector<vector<int> > palindromePairs_hash2(vector<string>& words) {
        set<vector<int> > ret;
        map<string, int> m;
        int i, j;

        // build map with reverse word as key, index as value
        for (i = 0; i < words.size(); ++i)
            m[string(words[i].rbegin(), words[i].rend())] = i;

        for (i = 0; i < words.size(); ++i) {
            // we aren't afraid of duplicate results, so using "j <= words[i].size()" rather than "<"
            for (j = 0; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);

                if (is_panlindrome(left) && m.count(right) > 0 && m[right] != i)
                    ret.insert(vector<int>{m[right], i});
                if (is_panlindrome(right) && m.count(left) > 0 && m[left] != i) {
                    ret.insert(vector<int>{i, m[left]});
                }
            }
        }
        return vector<vector<int> >(ret.begin(), ret.end());
    }

private:
    bool is_panlindrome(const string& s) {
        int n = s.size();
        for (int i = 0; i < n/2; ++i) {
            if (s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> words = {"bat", "tab", "cac"};
    vector<vector<int> > result = sol.palindromePairs(words);
    vector<vector<int> > result2 = sol.palindromePairs_hash2(words);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------- " << endl;
    for (int i = 0; i < result2.size(); ++i) {
        for (int j = 0; j < result2[i].size(); ++j) {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }
}

