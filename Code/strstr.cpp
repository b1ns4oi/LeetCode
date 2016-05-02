class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() == 0)
            return 0;

        if (needle.size() > haystack.size())
            return -1;

        int i, j, k;
        // pay attention to the requirement of i,
        // if instead, wrote as "i < haystack.size()", will not pass
        for (i = 0; i <= haystack.size() - needle.size(); ++i) {
            for (j = 0, k = i; k  < haystack.size() && j < needle.size() && haystack[k] == needle[j]; ++k, ++j)
                ;
            if (j == needle.size())
                return i;
        }
        return -1;
    }
};