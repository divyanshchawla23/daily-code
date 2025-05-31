class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> st(deadends.begin(),deadends.end());
        if(st.find("0000")!=st.end()) return -1;
        queue<pair<string,int>> q;
        string start = "0000";
        q.push({start,0});
        st.insert(start);

        while(!q.empty()){
            string curr = q.front().first;
            int level = q.front().second;
            q.pop();

            if(curr==target) return level;

            for(int i =0;i<4;i++){
                char c = curr[i];

                char dec = (c=='0') ? '9' : c-1;
                char inc = (c=='9') ? '0' : c+1;

                curr[i]=dec;
                if(st.find(curr)==st.end()){
                    st.insert(curr);
                    q.push({curr,level+1});
                }

                curr[i]=inc;
                if(st.find(curr)==st.end()){
                    st.insert(curr);
                    q.push({curr,level+1});
                }

                curr[i]= c;
            }
        }

        return -1;


    }
};