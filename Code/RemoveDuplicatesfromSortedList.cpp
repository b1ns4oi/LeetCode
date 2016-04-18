#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* construct(const vector<int>& v) {
    ListNode *head = 0;
    for (vector<int>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        ListNode *node = new ListNode(*it);
        node->next = head;
        head = node;
    }
    return head;
}
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        ListNode *next;
        int val;
        for (; p;) {
            val = p->val;
            for (next = p->next; next && next->val == val; next = next->next) {
                ;
            }
            p->next = next;
            p = next;
        }
        return head;
    }
};


int main(int argc, char *argv[])
{
    
    ListNode *p = construct(vector<int>{1,2,3,3,3});
    Solution sol;
    ListNode *result = sol.deleteDuplicates(p);
    for (; result; result = result->next) {
        cout << result->val << " ";
    }
    cout << endl;
}
