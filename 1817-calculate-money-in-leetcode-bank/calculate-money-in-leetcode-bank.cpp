class Solution {
public:
    int totalMoney(int n) {
        
        int t = n / 7;
        int f = 28; // first term
        int l = 28+(t-1)*7; // last term

        int res = t*(f+l)/2;    // AP result

        
    //  ---------last week------------
    
        int s_m = 1+t;
        for(int i =1;i<=(n%7);i++){
            res+=s_m;
            s_m++;
        }

        return res;

    }
};