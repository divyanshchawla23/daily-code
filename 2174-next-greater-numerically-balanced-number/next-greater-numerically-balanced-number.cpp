class Solution {
public:
    bool isValid(int n){
        vector<int>v(10);
        string s = to_string(n);
        for(char &c:s){
            v[c-'0']++;
        }

        for(int i =0;i<10;i++){
            if(v[i]!=0 && v[i]!=i){
                return false;
            }
        }
        return true;

    }
    int nextBeautifulNumber(int n) {
        for(int i = n+1;i<=1224444;i++){
            if(isValid(i)){
                return i;
            }
        }
        return -1;
    }
};