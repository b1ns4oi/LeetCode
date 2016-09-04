class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, n = digits.size();

        for (i = n-1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                break;
            }
            else
                digits[i] = 0;
        }
        // add one digit to left-most
        if (i < 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};