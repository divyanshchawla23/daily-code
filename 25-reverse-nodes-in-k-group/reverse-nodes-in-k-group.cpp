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
private:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* before = NULL;

        while(temp){

            ListNode* after = temp->next;

            temp -> next = before;

            before = temp;

            temp = after;

        }

        return before;
    }
    ListNode* kThNodeutil(ListNode* head, int k){

        ListNode* temp = head;

        while(temp && k>1){
            temp = temp->next;
            k--;
        }

        if(temp == NULL){
            return NULL;
        }

        return temp;

    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* before = NULL;
        ListNode* after = NULL;

        while(temp){

            ListNode* kthNode = kThNodeutil(temp,k);

            if(kthNode==NULL){
                if(before){
                    before->next = temp;
                }
                break;
            }

            ListNode* after = kthNode->next;
            kthNode->next = NULL;

            reverse(temp);

            if(temp==head){
                head = kthNode;
            }
            else{
                before->next = kthNode;
            }

            before = temp;
            temp = after;
        }



        return head;
    }
};