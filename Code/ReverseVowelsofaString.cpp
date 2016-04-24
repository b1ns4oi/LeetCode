class Solution {
public:
    string reverseVowels(string s) {
        set<char> char_set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        size_t n = s.size();
        int i, j;

        for (i = 0, j = n-1; i < j; ++i, --j) {
            while (char_set.count(s[i]) == 0)
                ++i;
            while (char_set.count(s[j]) == 0)
                --j;
            if (i < j) {
                char t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
        return s;
    }
};