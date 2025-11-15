class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int cntOf1 = 0;
        int op = 0;

        for(int i =0;i<n;i++){
            if(s[i]=='1'){
               cntOf1++; 
            }
            else{
                op += cntOf1;
                while(i<n && s[i]=='0'){
                    i++;
                }
                i--;
            }
        }


        return op;
    }
};         