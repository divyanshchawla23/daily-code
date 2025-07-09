class Solution {
private:
    bool isEven(int a){
        if(a%2==0) return true;
        else return false;
    }
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 1 ;i<nums.size();i++){
            if(isEven(nums[i])==isEven(nums[i-1]))return false;
        }
        return true;
    }
};