class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i =0;
        int j =0;
        int left = 0;
        int right =0;

        int n = version1.size();
        int m = version2.size();

        while(i<n || j<m){

            while(i<n && version1[i]!='.'){
                left = left * 10 + (version1[i]-'0');
                i++;
            }

            while(j<m && version2[j]!='.'){
                right = right * 10 + (version2[j]-'0');
                j++;
            }

            if(left<right) return -1;
            else if (left>right) return 1;

            left=0;
            right=0;
            i++;
            j++;


        }
        return 0;
    }
};