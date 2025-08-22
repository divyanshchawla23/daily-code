class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int total = x+y;
        queue<int>q;
        int dir[4]={-x,x,-y,y};
        q.push(0);
        vector<int>vis(total+1,0);
        vis[0]=1;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(x==target) return true;
            
            for(int i =0;i<4;i++){
                int water = x + dir[i];
                if(water>=0 && water<=total){
                    if(!vis[water]){
                        q.push(water);
                        vis[water]=1;
                    }
                }
            }
        }

        return false;
    }
};