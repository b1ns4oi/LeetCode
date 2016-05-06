#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        for (int i = 0; num ; num /= 10, i += 2) {
            int n = num % 10;
            ret = f(n, i) + ret;
        }
        return ret;
    }
    
    /* n :      [0 ... 9]
    ** index:   bit of 'n' in 'num', used to find related Roman character
    */
    string f(int n, int index) {
        string ret;
        switch (n) {
            case 0: 
                break;
            case 1:
            case 2:
            case 3:
                ret = string(n, v[index]);
                break;
            case 4:
                ret += v[index];
                ret += v[index+1];
                break;
            case 5:
                ret += v[index+1];
                break;
            case 6:
            case 7:
            case 8:
                ret += v[index+1];
                ret += string(n-5, v[index]);
                break;
            case 9:
                ret += v[index];
                ret += v[index+2];
                break;
        }
        return ret;
    }
private:
    vector<char> v = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
};

int main(int argc, char *argv[]) {
    Solution sol;
    string result = sol.intToRoman(stoi(argv[1]));
    cout << result << endl;
}
