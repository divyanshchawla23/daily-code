class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start = 0;
        int end = -1;
        for(int i =0;i<word.size();i++){
            if(word[i]==ch){
                end = i;
                break;
            }
        }
        cout << end;

        while(start<=end){
            char replace = word[start];
            word[start]= word[end];
            word[end]= replace;

            start++;end--;
        }


        if(end == -1) return word;

        return word;
    }
};