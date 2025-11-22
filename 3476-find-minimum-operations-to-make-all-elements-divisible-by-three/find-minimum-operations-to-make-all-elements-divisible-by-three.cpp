class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;

        for(auto & it: nums){
            if(it%3!=0){
                op++;
            }
        }

        return op;
    }
};