class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& cc) {
        int cnt = 0;
        auto comp = [](int a, int b){
            return a>b;
        };
        sort(cc.begin(),cc.end(),comp);
        
        int total_apples = accumulate(a.begin(),a.end(),0);

        int i = 0;
        while(total_apples>0){
            total_apples -= cc[i];
            cnt++;
            i++;
        }

        return cnt;
    }
};