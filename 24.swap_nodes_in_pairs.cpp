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
#include <iostream>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        if (!(head->next)) {
            return head;
        }

        auto prev = head;
        auto next = head;
        bool canSwap = false;

        while (next->next) {
            prev = next;
            next = next->next;
            canSwap = !canSwap;
            if (canSwap) {
                int temp = next->val;
                next->val = prev->val;
                prev->val = temp;
                std::cout << prev->val << std::endl;
                std::cout << next->val << std::endl;
            }
        }
        return head;
    }
};
