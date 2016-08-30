#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // First version: get all permutations, then find the k-th one by index
    // get 'Time Limit Exceeded' error
    string getPermutation(int n, int k) {
        vector<vector<char> > permutations = getAllPermutation(n);

        if (k > permutations.size())
            return string();

        return string(permutations[k-1].begin(), permutations[k-1].end());
    }

    // This version won't save all the permutations
    // we only care the k-th element, just count as we do permutations, if we found the k-th element,
    // save it, all subsequent recursive calling will not get performed.
    // Thus, it should be faster than 'getPermutation()'
    // But unfortunately, it still got 'Time Limit Exceeded'
    string getPermutation_2(int n, int k) {
        vector<char> elements, ret;
        int kk = 0;

        // initialize elements
        for (int i = 1; i <= n; ++i)
            elements.push_back(i+'0');

        getAllPermutation_2_recur(elements, 0, k, kk, ret);
        return string(ret.begin(), ret.end());
    }

    // Version 3: find k-th element by some special properties of permutations
    // this version get passed
    //
    // time complexity: O(n)
    string getPermutation_3(int n, int k) {
        vector<char> elements, ret;
        vector<int> factorial(n+1, 1);

        // initialization
        for (int i = 1; i <= n; ++i) {
            elements.push_back(i+'0');
            factorial[i] = factorial[i-1]*i;
        }

        for (int sz, index; (sz = elements.size()) > 1; ) {
            index = (k-1)/factorial[sz-1];
            ret.push_back(elements[index]);
            elements.erase(elements.begin()+index);
            k -= index*factorial[sz-1];
        }
        ret.push_back(elements[0]);     // don't forget the last element

        return string(ret.begin(), ret.end());
    }

private:
    void getAllPermutation_2_recur(vector<char>& elements, int idx, int k, int& kk, vector<char>& ret) {
        if (kk >= k)    // if found, all subsequent recursive calling will not get performed
            return;

        if (idx >= elements.size()-1) {
            if (++kk == k)  // adjust the count, save the result if found
                ret = elements;
            return;  
        }

        for (int i = idx; i < elements.size(); ++i) {
            move(elements, idx, i);
            getAllPermutation_2_recur(elements, idx+1, k, kk, ret);
            recover(elements, idx, i);
        }
    }

    vector<vector<char> > getAllPermutation(int n) {
        vector<char> elements;
        vector<vector<char> > ret;

        // initialize elements
        for (int i = 1; i <= n; ++i)
            elements.push_back(i+'0');

        getAllPermutation_recur(elements, 0, ret);
        return ret;
    }

    void getAllPermutation_recur(vector<char>& elements, int idx, vector<vector<char> >& ret) {
        if (idx >= elements.size()-1) {
            ret.push_back(elements);
            return;          
        }
        getAllPermutation_recur(elements, idx+1, ret);
        for (int i = idx+1; i < elements.size(); ++i) {
            move(elements, idx, i);
            getAllPermutation_recur(elements, idx+1, ret);
            recover(elements, idx, i);
        }
    }

    // get element at 'j', insert at 'i'
    // assume i <= j
    void move(vector<char>& elements, int i, int j) {
        char t;
        for (t = elements[j]; i < j; --j)
            elements[j] = elements[j-1];
        elements[i] = t;
    }

    // recover what gets done with 'move()'
    void recover(vector<char>& elements, int i, int j) {
        char t;
        for (t = elements[i]; i < j; ++i)
            elements[i] = elements[i+1];
        elements[j] = t;
    }
};

int main() 
{
    Solution sol;
    string ret1 = sol.getPermutation(9, 100);
    string ret2 = sol.getPermutation_2(9, 100);
    string ret3 = sol.getPermutation_3(9, 100);

    cout << ret1 << endl;
    cout << ret2 << endl;
    cout << ret3 << endl;
}