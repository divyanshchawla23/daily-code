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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }
        int pwr = 0;
        long long ans = 0;
        while(!st.empty()){
            int a = st.top();
            st.pop();
            ans+= a * pow(2,pwr);
            pwr++;
        }
        return (int)ans;
    }
};