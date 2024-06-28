class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //left smaller index

        stack<pair<int ,int>> s;
        vector<int> left;
        int psudoIndex = -1 ;

        for(int i =0;i<heights.size();i++){
            if(s.size()==0) {
                left.push_back(psudoIndex);
            }
            else if(s.size()>0 && s.top().first < heights[i]){
                left.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first >=heights[i]){
                while(s.size()>0 && s.top().first >=heights[i]){
                    s.pop();
                }

                    if(s.size()==0){
                        left.push_back(psudoIndex);
                    }

                    else{
                        left.push_back(s.top().second);
                    }
                
            }

            s.push({heights[i],i});
        }

        //right smaller index
        while(s.size()>0){
            s.pop();
        }
        
        psudoIndex = heights.size();

        vector<int> right;
        

        for(int i = heights.size()-1; i>=0 ;i--){
            if(s.size()==0) {
                right.push_back(psudoIndex);
            }
            else if(s.size()>0 && s.top().first < heights[i]){
                right.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first >=heights[i]){
                while(s.size()>0 && s.top().first >=heights[i]){
                    s.pop();
                }

                    if(s.size()==0){
                        right.push_back(psudoIndex);
                    }

                    else{
                        right.push_back(s.top().second);
                    }
                
            }

            s.push({heights[i],i});
        }
            reverse(right.begin(),right.end());

            

            vector<int> ans;
            int area = 1;
            for(int i =0;i<heights.size();i++){
                area = heights[i] * (right[i]-left[i]-1);
                ans.push_back(area);
            }

            
        return *max_element(ans.begin(),ans.end());
    }
};