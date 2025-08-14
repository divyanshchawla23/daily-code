class Solution {
public:
    string largestGoodInteger(string num) {
        for(char c = '9'; c>='0';c--){
            string sub(3,c);
            if(num.find(sub)!=string::npos){
                return sub;
            }
        }
        return "";    
    }
};