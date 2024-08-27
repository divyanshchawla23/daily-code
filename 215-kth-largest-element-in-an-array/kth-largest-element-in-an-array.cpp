class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>> hp;

        for(int i =0;i<nums.size();i++){
            hp.push(nums[i]);
            if(hp.size()>k){
                hp.pop();
            }
        }
        return hp.top();
    }
};