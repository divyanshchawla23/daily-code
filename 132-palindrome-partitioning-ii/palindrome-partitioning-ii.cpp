class Solution {
public:
    int t[2002][2002];
    bool ispallindrome(string &s,int i,int j){
        int st=i;
        int e=j;
        while(st<e){
            if(s[st]!=s[e])return false;
            st++;
            e--;
        }
        return true;
    }
    int solve(string &s,int i,int j){
        if(i>=j || ispallindrome(s,i,j)){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            
            if(ispallindrome(s,i,k)){
                int temp=1+solve(s,k+1,j);
                ans=min(ans,temp);
            }
        }
        return t[i][j]=ans;
    }
    
    int minCut(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
    }
};