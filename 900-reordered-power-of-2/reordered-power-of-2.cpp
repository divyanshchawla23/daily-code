class Solution {
public:
    string helper(int n){
        string s = to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s = helper(n);

        for(int i =0;i<=29;i++){
            if(s==helper(pow(2,i))) return true;
        }

        return false;
    }
};