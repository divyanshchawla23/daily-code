class Solution {
public:
    int myAtoi(string s) {

        int maxi = INT_MAX;
        int mini = INT_MIN;

       if(s.size()==0){
        return 0;
       }
       int i =0;
       while(i<s.size() && s[i]==' '){
        i++;
       }
       s= s.substr(i);
       int sign = 1;
       long ans =0;
       i=0;

       if(s[0]=='-') sign=-1;
       if(s[0]=='-' ||s[0]=='+'){
        i=1;
       }
       

       while(i<s.size()){
        if(s[i]==' ' || !isdigit(s[i])) break;

        ans = (ans *10) + (s[i]-'0');
        i++;

        if(sign == 1 && ans>maxi) return maxi;
        if(sign == -1 && (-1*ans)<mini) return mini;
        


       }
        return sign*ans;
    }
};