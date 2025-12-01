class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }

        map<int,int>mpp;

        for(auto it: hand){
            mpp[it]++;
        }

        while(!mpp.empty()){
            int el = mpp.begin()->first;

            for(int i =0;i<groupSize;i++){
                if(mpp[el+i]==0){
                    return false;
                }
                mpp[el+i]--;
                if(mpp[el+i]<1){
                    mpp.erase(el+i);
                }
            }

        }

        return true;
        
    }
};