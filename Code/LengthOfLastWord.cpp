#include <string>
#include <cctype>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator it;
        int ret = 0;

        for (it = s.rbegin(); it != s.rend(); ++it)
            if (!isspace(*it))
                break;
        while (it != s.rend() && !isspace(*it)) {
            ++ret;
            ++it;
        }
        return ret;
    }
};


int main()
{
    Solution s;
    cout << s.lengthOfLastWord("aaaaabcdefg\n") << endl;
}

