struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = NULL, *next;
        for (; head; head = next) {
            next = head->next;
            head->next = prev;
            prev = head;
        }
        return prev;
    }

    ListNode* reverseList_recursion(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *last = reverseList_recursion(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};