class Solution {
public:
    int compress(vector<char>& chars) {
        int index =0;
        int i =0;
        int n = chars.size();

        while(i<n){
            int cnt =0;
            char current = chars[i];

            while(i<n && current == chars[i]){
                cnt++;
                i++;
            }

            chars[index]= current;
            index++;

            if(cnt>1){
            
                string countString = to_string(cnt);

                for(auto it : countString){
                    chars[index] =it;
                    index++;
                }
            }


        }

        return index;
    }
};