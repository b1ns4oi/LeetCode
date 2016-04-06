#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            cout << "empty" << endl;
            return "";
        }
        string::size_type len = shortest_len(strs);
        string::size_type index = 0;

        for (string::size_type i = 0; i < len && is_common(strs, i); ++i) 
            ++index;

        return strs[0].substr(0, index);
    }
private:
    bool is_common(vector<string>& strs, int i) {
        char c = strs[0][i];
        vector<string>::iterator it;
        for (it = strs.begin()+1; it != strs.end(); ++it) {
            if (c != (*it)[i])
                return false;
        }
        return true;
    }

    string::size_type shortest_len(vector<string>& strs) {
        string::size_type len = strs[0].size();
        vector<string>::iterator it;
        for (it = strs.begin()+1; it != strs.end(); ++it)
            if (it->size() < len)
                len = it->size();
        return len;
    }

};


int main()
{
    Solution s;
    vector<string> v = {"aca", "acabcef"};
    cout << s.longestCommonPrefix(v) << endl;
}

