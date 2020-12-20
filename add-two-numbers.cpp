/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto start = new ListNode();
        int carry = 0;
        auto res = start;
        start->next = res;
        while(l1) {        
            res->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val) / 10;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return start->next;
    } 
};
