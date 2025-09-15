class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        bool canType = 1;

        for(char &ch : text){
            if(ch == ' '){
                if(canType){
                    cnt++;
                }
                canType = 1;
            }
            else if(brokenLetters.find(ch)!=string::npos){
                canType = 0;
            }
        }

        if(canType){
            cnt++;
        }


        return cnt;
    }
};