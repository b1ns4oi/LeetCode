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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = swapPairs(head->next->next);
        ListNode *new_head = head->next;
        head->next->next = head;
        head->next = p;
        return new_head;
    }
};

int main(int argc, char *argv[])
{
    ListNode *p = construct(vector<int>{1,2,3,4});
    Solution sol;
    ListNode *result = sol.swapPairs(p);
    for (; result; result = result->next) {
        cout << result->val << " ";
    }
    cout << endl;
}