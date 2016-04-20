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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev = NULL;
        ListNode *p_m = head, *p_n, *next;
        int i;

        for (i = 0; i < m-1; ++i) {
            prev = p_m;
            p_m = p_m->next;
        }
        p_n = p_m;
        for (i = 0; i < n-m; ++i, p_n = p_n->next)
            ;
        next = p_n->next;
        p_n->next = NULL;

        if (!prev)
            head = reverse(p_m);
        else
            prev->next = reverse(p_m);
        p_m->next = next;
        return head;
    }

    ListNode* reverse(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};


int main(int argc, char *argv[])
{
    
    ListNode *p = construct(vector<int>{1,2,3,4,5});
    Solution sol;
    ListNode *result = sol.reverseBetween(p, 1, 4);
    for (; result; result = result->next) {
        cout << result->val << " ";
    }
    cout << endl;
}
