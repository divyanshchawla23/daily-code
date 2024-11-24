class Solution {
private:
    bool bothE(int n, int m){
        if(n%2==0&&m%2==0) return true;
        else return false;
    }

    bool bothO(int n, int m){
        if(n%2!=0&&m%2!=0) return true;
        else return false;
    }
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int e=0;
        int o=1;

        while(e<n&&o<n){
            if(bothE(e,nums[e])){
                e+=2;  
            }
            else if(bothO(o,nums[o])){ 
                o+=2;
            }
            else{
                swap(nums[e],nums[o]);
                e+=2;
                o+=2;
            }
        }

        return nums;
    }
};