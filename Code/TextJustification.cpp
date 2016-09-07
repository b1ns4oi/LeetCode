#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        int n_words = words.size(), n_spaces, n_spaces_each, n_remain, n_slot;
        int i, j, k;

        for (i = 0; i < n_words; ) {
            int len = 0;
            vector<int> word_indices;

            // construct next line
            for (j = i; j < n_words && len + words[j].size() <= maxWidth; ++j) {
                word_indices.push_back(j);
                len += words[j].size() + 1;   // '1' stands for length of a space
            }

            n_spaces = maxWidth - (len - word_indices.size());  // n spaces left for padding
            n_slot = word_indices.size()-1;
            if (n_slot != 0) {
                // if not evenly divided, there're 'n_remain' slot should have one more space
                n_remain = n_spaces % (word_indices.size()-1);
                // 'n_spaces' for each slot
                n_spaces_each = n_spaces / (word_indices.size()-1);
            }
            
            string s(words[word_indices[0]]);

            // construct line based on words indexed by indices in 'word_indices'
            if (j == n_words) {
                // last line
                for (k = 1; k < word_indices.size(); ++k) {
                    s.append(1, ' ');
                    s += words[word_indices[k]];
                }
                s.append(maxWidth-len+1, ' ');
            }
            else {
                for (k = 1; k < word_indices.size(); ++k) {
                    s.append(n_spaces_each, ' ');
                    if (n_remain-- > 0)
                        s += ' ';
                    s += words[word_indices[k]];
                }
                if (n_slot == 0) {
                    s.append(n_spaces, ' ');                 
                }
            }
            vec.push_back(s);
            i = j;
        }
        return vec;
    }
};

int main() 
{
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> ret = sol.fullJustify(words, 14);
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << endl;
    }
}
