#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////


class Solution {
public:
    // Recursively
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0)
            return head;
        ListNode dummy(0);
        ListNode *p = &dummy;
        dummy.next = head;

        f(p, n);
        return p->next;
    }

private:
    // return length of list, if node (which should be deleted) found, do deletion operation
    int f(ListNode* head, int n) {
        if (head == NULL)
            return 0;
        int sub_len = f(head->next, n);
        if (sub_len == n) {
            head->next = head->next->next;
        }
        return 1 + sub_len;
    }
};

int main(int argc, char *argv[])
{
    ListNode *p = construct(vector<int>{1,2,3});
    Solution sol;
    ListNode *result = sol.removeNthFromEnd(p, 1);
    for (; result; result = result->next) {
        cout << result->val << " ";
    }
    cout << endl;
}
