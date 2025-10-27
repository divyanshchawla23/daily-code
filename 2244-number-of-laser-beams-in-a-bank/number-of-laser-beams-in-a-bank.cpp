class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        int res = 0;

        for(int i =0;i<bank.size();i++){
            int curr = 0;
            for(char c: bank[i]){
                if(c=='1'){
                    curr++;
                }
            }
            if(curr!=0) v.push_back(curr);
        }

        if(v.empty()){
            return 0;
        }

        for(int i =0;i<v.size()-1;i++){
            res+=(v[i]*v[i+1]);
        }

        return res;
       
    }
};