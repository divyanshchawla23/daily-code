class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        set<string>st(wordList.begin(),wordList.end());

        if(st.find(endWord)==st.end()) return 0;

        q.push({beginWord,1});

        while(!q.empty()){
            string wrd = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(wrd == endWord) return steps;

            for(int i =0;i<wrd.size();i++){
                char original = wrd[i];
                for(char ch = 'a';ch<='z';ch++){
                    wrd[i]=ch;
                    if(st.find(wrd)!=st.end()){
                        st.erase(wrd);
                        q.push({wrd,steps+1});
                    }
                }
                wrd[i]= original;
            }


        }

        return 0;
    }
};