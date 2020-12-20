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
#include <vector>

using namespace::std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto resHead = new ListNode();
        auto resChange = resHead;

        bool isDone = false;
        int minIndex = 0;

        while (!isDone) {
            isDone = true;
            int minIndex = 0;
            int min = INT_MAX;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    isDone = false;
                    if (lists[i]->val < min) {
                        minIndex = i;
                        min = lists[i]->val;
                    }
                }
            }
            if (isDone) {
                break;;
            }
            resChange->next = new ListNode(min);
            resChange = resChange->next;
            lists[minIndex] = lists[minIndex]->next;
        }
        return resHead->next;
    }
};
