class Solution {
public:
    
    // memoization
    
    vector<int> dp;
    
    int fun(int n)
    {
        if(n<0)
            return 0;
        
        if(n==0)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int num1 = fun(n-1);
        int num2 = fun(n-2);
        
        return dp[n] = num1 + num2;
    }
    
    int climbStairs(int n) 
    {
        dp.clear();
        dp.resize(n+1,-1);
        return fun(n);
    }
};