class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) {
            return false;
        }
        
        string newString = s+s;

        if(newString.find(goal)!= -1){
            return true;
        }
        else return false;
    }
};