class Solution {
public:
    string reverseString(string s) {
        size_t n = s.size();
        for (int i = 0; i < n/2; ++i) {
            char c = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = c;
        }
        return s;
    }
};