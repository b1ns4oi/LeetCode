#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head;
        for (int i = 0; i < k-1 && p; ++i) {
            p = p->next;
        }
        if (p == NULL)
            return head;

        ListNode *next_head = reverseKGroup(p->next, k);
        ListNode *new_head = reverse(head, p);
        // Now 'head' becomes end of the reversed sub-list
        head->next = next_head;
        return new_head;
    }

private:
    // This function reverse linked-list started from 'l', ended to 'r'.
    ListNode* reverse(ListNode *l, ListNode *r) {
        ListNode *prev = NULL, *next = NULL;
        for (; l != r; l = next) {
            next = l->next;
            l->next = prev;
            prev = l;
        }
        r->next = prev;
        return r;
    }
};

int main(int argc, char *argv[])
{
    ListNode *p = construct(vector<int>{1,2});
    Solution sol;
    ListNode *result = sol.reverseKGroup(p, 3);
    for (; result; result = result->next) {
        cout << result->val << " ";
    }
    cout << endl;
}