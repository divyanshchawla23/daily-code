class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        
        int mx=0;
        int mn = 0;

        for (int i =0;i<n;i++){
            
            if(s[i]=='('){
                mx++;
                mn++;
            }

            else if(s[i]==')'){
                mx--;
                mn--;
            }

            else {
                mx++;
                mn--;
            }
            if(mx<0) return false;
            if (mn<0) mn =0;


        }
        return (mn==0);
    }
};