class Solution {
public:
    int countDigits(int num) {
        string s = to_string(num);
        int cnt =0;

        for(char c : s){
            int number = c - '0';
            if(num%number==0) cnt++;
        }

        return cnt;
    }
};