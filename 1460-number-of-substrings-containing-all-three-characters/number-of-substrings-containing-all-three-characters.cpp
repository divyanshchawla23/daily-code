class Solution {
public:
    int numberOfSubstrings(string s) {
        
        // int last[3]= {-1,-1,-1};
         map<char, int> last = {{'a', -1}, {'b', -1}, {'c', -1}};
        int cnt = 0 ;

        for(int i =0;i<s.size();i++){

            
            last[s[i]]= i;


            if(last['a'] >= 0 && last['b'] >= 0 && last['c'] >= 0){
                int mini = min(last['a'],last['b']);
                int mini1= min(mini , last['c']);
                
                cnt = cnt + (1+ mini1) ;

            }
        }
        return cnt;
    }
};