class Solution {
public:
    void reverseWord(string &s, int left, int right){

        while(left<=right){
            swap(s[left],s[right]);
            left++;right--;
        }

    }
    string reverseWords(string s) {
        int n = s.size();
        string word = "";
        int left = 0;
        int right = 0;

        while(right<=n){
            if(right == n || s[right] == ' '){
                reverseWord(s,left,right-1);
                right++;
                left = right;
            }
            right++;
        }

        return s;
    }
};