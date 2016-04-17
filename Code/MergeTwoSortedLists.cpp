class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2)
            return !l1 ? l2 : l1;

        ListNode dummy_head(0);
        ListNode *tail = &dummy_head;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        tail->next = !l1 ? l2 : l1;
        return dummy_head.next;
    }

    // recursive version
    ListNode* mergeTwoLists_Recur(ListNode* l1, ListNode* l2) {
            if (!l1)
                return l2;
            if (!l2)
                return l1;

            if (l1->val < l2->val) {
                l1->next = mergeTwoLists_Recur(l1->next, l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists_Recur(l1, l2->next);
                return l2;
            }
        }
};