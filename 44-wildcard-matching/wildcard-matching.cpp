class Solution {
private:
    
    bool check(string &S1, int i) {
        for (int j = 1; j <= i; j++) {
            if (S1[j-1] != '*')
                return 0;
        }
        return 1;
    }

    bool f(int n, int m, string s, string p,vector<vector<int>> &dp){

        if(n==0 && m==0) return true;
        if(n==0 && m>0) return check(p,m);
        if(m==0 && n>0){
            return false;
        }

        if (dp[n][m] != -1) return dp[n][m];

        if(s[n-1]==p[m-1] || p[m-1]=='?'){
            return dp[n][m]=f(n-1,m-1,s,p,dp);
        }else{
            if(p[m-1]=='*'){
                return dp[n][m]= (f(n,m-1,s,p,dp) || f(n-1,m,s,p,dp));
            }else return false;
        }

    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, false));
       

        for(int i =0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0) dp[i][j] = 1;
            }
        }

        for(int mm = 1 ; mm<=m;mm++){
            dp[0][mm] = check(p,mm);
        }

        for(int mm = 1 ; mm<=n;mm++){
            dp[mm][0] = 0;
        }

        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(s[i-1]==p[j-1] || p[j-1]=='?'){
                        dp[i][j]=dp[i-1][j-1];
                    }else{
                        if(p[j-1]=='*'){
                            dp[i][j]= (dp[i][j-1] || dp[i-1][j]);
                    }else dp[i][j] =  0;
                }
            }
        }

        return dp[n][m];
        // return f(n,m,s,p,dp);
    }
};