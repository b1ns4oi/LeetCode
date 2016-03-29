#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	ListNode *p;
        int dif = count(headA) - count(headB);
        if(dif < 0) {
        	dif *= -1;
        	p = headA; headA = headB; headB = p;  // make headA the long one 
        }
        while(dif--) 
        	headA = headA->next;
        for(; headA != headB && headA != NULL; headA = headA->next, headB = headB->next)
        	;
        return headA;
    }

private:
	int count(ListNode *p) {
		int ret = 0;
		while(p != NULL) {
			ret++;
			p = p->next;
		}
		return ret;
	}
};

void list_print(ListNode *p) {
	for(; p; p = p->next)
		cout << p->val << " ";
	cout << endl;
}

int main()
{
	ListNode n0(0);
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3); ListNode n4(4); ListNode n5(5); ListNode n7(7); ListNode n6(6);
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n5;
	n5.next = &n6;
	n6.next = &n7;

	n3.next = &n4;
	// n4.next = &n5;

	list_print(&n0);
	list_print(&n3);

	Solution s;
	ListNode *ret = s.getIntersectionNode(&n0, &n3);
	if(ret != NULL)
		cout << ret->val << endl;
	else
		cout << "NULL Ptr" << endl;
}