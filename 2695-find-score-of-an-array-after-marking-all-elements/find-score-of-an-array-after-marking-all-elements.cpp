class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        auto comp = [](pair<int,int>p1,pair<int,int>p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }else{
                return p1.first<p2.first;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> marked(n,0);

        for(int i =0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
            auto p = pq.top();
            int num = p.first;
            int ind = p.second;
            pq.pop();

            if(!marked[ind]){
                score += num;
                marked[ind]=1;
                if(ind>=1) marked[ind-1]=1;
                if(ind<=n-2) marked[ind+1]=1;
            }
        }

        return score;
    }
};