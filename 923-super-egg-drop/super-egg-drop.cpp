class Solution {
public:
    int  t[101][10001];
    int solve(int k,int n){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(t[k][n]!=-1){
            return t[k][n];
        }
       
        int minm=INT_MAX;
        int l=1;
        int h=n;
        int temp=0;
        while(l<=h){
            int mid=(l+h)/2;
            int left=solve(k-1,mid-1);
            int right=solve(k,n-mid);
            temp=1+max(left,right);
            if(left<right){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            minm=min(temp,minm);

        }
        
        return t[k][n]= minm;
    }
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        int ans=solve(k,n);
        return ans;
    }

    
};