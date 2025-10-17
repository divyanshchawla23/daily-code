class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inD(n);

        for(auto it:edges){
            inD[it[1]]++;
        }

        int champ = -1;
        int cnt = 0;

        for(int i =0;i<inD.size();i++){
            if(inD[i]==0){
                champ=i;
                cnt++;
            }
        }

        if(cnt == 1) return champ;
        else return -1;
    }
};