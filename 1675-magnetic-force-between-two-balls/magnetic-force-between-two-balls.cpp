class Solution {
public:
    bool canWePlace(vector<int>& position, int mid , int cows){
        int cntCow =1;
        int last = position[0];

        for(int i =1;i<position.size();i++){
            if(position[i]-last>= mid){
                cntCow ++;
                last = position[i];
            }
            if(cntCow>=cows) return true;
        }
             return false ;

    }
    
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());

        int low = 1;
        int high = *max_element(position.begin(),position.end());

        int ans = INT_MIN;

        while(low<=high){

            int mid = (low +high)/2;

            if(canWePlace(position, mid , m)== true){
                ans = mid ;
               low = mid +1; 
            }

            else{
                high = mid -1 ;
            }
        }
        return ans ;
        
    }
};