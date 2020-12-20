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

using namespace::std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!(l1 || l2)) {
            return nullptr;
        }

        auto res = new ListNode();
        auto start = res;

        while (l1 && l2) {
            std::cout << l1->val << l2->val << std::endl;
            if (l1->val < l2->val) {
                std::cout << "first" << std::endl;
                res->val = l1->val;
                l1 = l1->next;
            } else {
                std::cout << "second" << std::endl;
                res->val = l2->val;
                l2 = l2->next;
            }

            res->next = new ListNode();
            res = res->next;
        }

        std::cout << "reach" << std::endl;

        auto prev = res;

        while (l1) {
            std::cout << "first" << std::endl;
            res->val = l1->val;
            prev = res;
            res->next = new ListNode();
            res = res->next;
            l1 = l1->next;
        }

        while (l2) {
            std::cout << "second" << std::endl;
            res->val = l2->val;
            prev = res;
            res->next = new ListNode();
            res = res->next;
            l2 = l2->next;
        }

        prev->next = nullptr;

        return start;
    }
};
