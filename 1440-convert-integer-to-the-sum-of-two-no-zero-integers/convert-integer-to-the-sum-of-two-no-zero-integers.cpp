class Solution {
public:
    bool nonZero(int n){
        string s = to_string(n);

        for(char c: s){
            if(c=='0') return false;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int i = 1;
        int j = n-1;

        while(i<=j){
            int sum = i + j;
            if(sum>n){
                j--;
            }else if(sum<n){
                i++;
            }else{
                while(!(nonZero(i)) || !(nonZero(j))){
                    i++;j--;
                }
                return {i,j};
            }
        }
        return {};
    }
};