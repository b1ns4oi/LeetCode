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
 
class Solution {
public:
    ListNode *mergeTwo(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwo(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwo(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;

        int i, j, len = lists.size();
        ListNode *p;
        while (len > 1) {
            for (i = 0; i < len/2; ++i) {
                lists[i] = mergeTwo(lists[i], lists[len-i-1]);
            }
            len -= len/2;
        }
        
        return lists.front();
    }
};
