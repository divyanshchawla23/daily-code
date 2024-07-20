/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
                return nullptr;
            }

            ListNode* t1 = headA;  
            ListNode* t2 = headB;  

            // Traverse the lists
            while (t1 != t2) {
                // Move to the next node in the list or switch to the other list if at the end
                t1 = (t1 == nullptr) ? headB : t1->next;
                t2 = (t2 == nullptr) ? headA : t2->next;
            }

            // Either both pointers are null (no intersection) or they meet at the intersection point
            return t1;
    }
};