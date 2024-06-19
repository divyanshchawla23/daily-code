class Solution {
public:

     long long MOD = 1'000'000'007;
    long long p(long long x,long long n){
        long long ans =1 ;
        if(n==0){
            return 1 ;
        }
        while (n>0){
        if(n%2==0){
            x= x*x%MOD;
            n= n/2;
        }
        
        else{
            ans = (x * ans)%MOD;
            n= n-1; 
        }}
        return ans ;
    }
    int countGoodNumbers(long long n) {
       long long even = (n+1)/2;
       long long odd = n/2;
       long long first = p(5,even)%MOD;
       long long second = p(4,odd)%MOD;

       return (int)((first*second)%MOD);
    }
};