/*  A question asked when interviewed in Tencent.
**
**  Write a program to print all permutations of the elements in array.
**
**  e.g.
**  array = {1,2,3}
**  permutation: 
**  1 2 3
**  1 3 2
**  2 1 3
**  2 3 1
**  3 2 1
**  3 1 2
*/
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& v, int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void permute_recur(vector<int>& v, int i, int j) {
    if (i == j) {
        for (auto e : v)
            cout << e << " ";
        cout << endl;
    }
    else {
        for (int k = i; k <= j; ++k) {
            swap(v, k, i);
            permute_recur(v, i+1, j);
            swap(v, k, i);
        }
    }
}

void permute(vector<int>& v) {
    permute_recur(v, 0, v.size()-1);
}

int main() {
    vector<int> v = {1,2,3};
    permute(v);
}
