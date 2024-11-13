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
    void insertion_sort(vector<int>&arr){
        int n = arr.size();

        for(int i =0;i<arr.size();i++){
            int j =i;
            while(j>0&& arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
                j--;
            }
        }
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> t;

        while(temp){
            t.push_back(temp->val);
            temp = temp->next;
        }

        insertion_sort(t);

        temp = head;

        for(int i =0;i<t.size();i++){
            temp->val = t[i];
            temp = temp ->next;
        }
        return head;

    }
};