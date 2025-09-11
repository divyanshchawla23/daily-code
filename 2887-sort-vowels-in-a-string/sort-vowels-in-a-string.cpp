class Solution {
public:
    bool isVowel(char c){
        char ch = tolower(c);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return true ;
        }
        else return false;
    }
    string sortVowels(string s) {
        vector<int> chars;
        for (char c : s) {
            if (isVowel(c)) {
                chars.push_back(c);
            }
        }
        sort(chars.begin(), chars.end());
       
        int i = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                c = chars[i];
                i++;
            }
        }
        return s;
    }
};