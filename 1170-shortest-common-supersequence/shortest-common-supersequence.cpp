class Solution {
public:
    int dp[1001][1001];
    
    void table(string s1, string s2 , int n, int m){

        for(int i =0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }

        for(int i =1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
            }
        }

    }


    string helper(string s1, string s2 , int n, int m){
        string ans = "";
        int i = n; int j = m;

        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;    j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    ans.push_back(s2[j-1]);
                    j--;
                }
                else{
                    ans.push_back(s1[i-1]);
                    i--;
                }
            }
        }

        while(i>0){
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());

        return ans;

    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        table(str1,str2,n,m);
        return helper(str1,str2,n,m);
        
       

    }
};