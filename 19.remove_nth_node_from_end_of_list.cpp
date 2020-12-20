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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;

        auto changeHead = head;
        auto resHead = head;

        while(head) {
            head = head->next;
            len++;
        }

        if (len == 1 && n == 1) {
            return nullptr;
        }

        if (len == 2) {
            if (n == 1) {
                changeHead->next = nullptr;
                return changeHead;
            } else if (n == 2){
                changeHead = changeHead->next;
                return changeHead;
            }
        }

        if (len == n) {
            changeHead = changeHead->next;

            return changeHead;
        }

        for (int i = 0; i < len - n - 1; ++i) {
            changeHead = changeHead->next;
        }
        std::cout << changeHead->val << std::endl;

        changeHead->next = changeHead->next->next;

        return resHead;
    }
};
