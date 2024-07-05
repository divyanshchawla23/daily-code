class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int > res(n ,1);

        //calculate the left prefix;

        for(int i =1 ;i<n;i++){
            res[i]= nums[i-1]* res[i-1];
        }
        
        //calculate right suffix and multiply 

        int right = 1;

        for(int i = n-1 ;i>=0;i--){
            res[i]= res[i]*right;
            right = right * nums[i];
        }
        return res;
    }
};