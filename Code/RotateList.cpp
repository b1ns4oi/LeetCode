#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    // Pay attention to this problem that 'k' can be larger than the length of the list
    // this leads to this subtle solution with tail node links to head to construct a circle
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        int n = 1;
        ListNode *tail, *ret;

        // count length
        for (tail = head; tail->next != NULL; tail = tail->next, ++n)
            ;
        tail->next = head;  // circle
        
        // find the k-th to the tail node
        if (k %= n)
            for (int i = 0; i < n-k; tail = tail->next, ++i)
                ;

        ret = tail->next;
        tail->next = NULL;  // remove the circle at some point
        return ret;
    }
};

void printnode(ListNode *p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() 
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    printnode(&n1);


    Solution sol;
    ListNode *p = sol.rotateRight(&n1, 2);
    printnode(p);

}
