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
    ListNode* swapPairs(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* after = NULL;
        ListNode* first = temp;
        ListNode* second = temp->next;
        ListNode* finalHead = NULL;

        while (first && second) {

            if (finalHead == NULL) {
                finalHead = second;
            }

            after = second->next;
            first->next = after;
            second->next = first;
            if (prev)
                prev->next = second;

            prev = first;

            first = after;
            if (first) {
                second = first->next;
            } else {
                second = NULL;
            }
        }

        return finalHead;
    }
};