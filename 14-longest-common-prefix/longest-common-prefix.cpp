class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Sort the strings
        sort(strs.begin(), strs.end());
        int n = strs.size();

        string a = strs[0];
        string b = strs[n-1];

        int i =0;
        int j = 0;
        string ans ="";


        while(i<strs[0].size() || j<strs[n-1].size() ){
            if(strs[0][i]==strs[n-1][j]){
                ans+= strs[0][i];
                i++;j++;
            }

            else break;
        }       
        return ans;
    }
};