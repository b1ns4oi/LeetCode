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
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        for (; head; ) {
            ListNode *pp = head;
            while (pp->next && pp->val == pp->next->val)
                pp = pp->next;
            if (pp != head) {
                prev->next = pp->next;
                head = pp->next;
            }
            else {
                head = head->next;
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};


int main(int argc, char *argv[])
{
    
    ListNode *p = construct(vector<int>{3});
    Solution sol;
    ListNode *result = sol.deleteDuplicates(p);
    for (; result; result = result->next) {
        cout << result->val << " ";
    }
    cout << endl;
}
