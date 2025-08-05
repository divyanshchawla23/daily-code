class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        vector<int> vis(m,0);
        int cnt = 0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(fruits[i]<=baskets[j] && vis[j]==0){
                    vis[j]=1;
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};