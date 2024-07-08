struct meeting {
   int start;
   int end;

};
class Solution {
public:
    static bool comparator(const meeting& m1, const meeting& m2) {
        return m1.end < m2.end;
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();
        struct meeting meet[n];
        
        for(int i =0;i<n;i++){
            meet[i].start = pairs[i][0];
            meet[i].end = pairs[i][1];
            
        }
         sort(meet, meet + n, comparator);
         
         int cnt = 1 ;
         int time = meet[0].end;
         for(int i =1;i<n;i++){
             if(meet[i].start>time){
                 cnt++;
                 time = meet[i].end;
             }
            
         }
         return cnt;
        
    }
};