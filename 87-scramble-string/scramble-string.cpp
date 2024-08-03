class Solution {
public:
    unordered_map <string , bool> mpp;
    bool isScramble(string a, string b) {
        if(a.compare(b)==0) return true;
        if (a.size() != b.size() || a.size() <= 1) return false;
        string temp = a+b;
        if(mpp.find(temp)!=mpp.end()) return mpp[temp];


        bool flag = false;
        int n = a.size();
         

        for(int i =1;i<n;i++){

            bool con1 = isScramble(a.substr(0,i),b.substr(n-i,i)) && isScramble(a.substr(i,n-i),b.substr(0,n-i));
            bool con2 = isScramble(a.substr(0,i),b.substr(0,i)) &&      isScramble(a.substr(i,n-i),b.substr(i,n-i));


            if(con1|| con2 ){
                flag = true;
                break;

            }
        }



        return mpp[temp] = flag;

        
    }
};