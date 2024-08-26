class Solution {
private:
    vector<int> findLeft (vector<int>& nums){
        stack<pair<int,int>> st;
        vector<int> ans;
        int psuedo = -1;

        for(int i =0;i<nums.size();i++){
            if(st.empty()) ans.push_back(psuedo);

            else if(!st.empty() && st.top().first < nums[i]) ans.push_back(st.top().second);
            else if(!st.empty() && st.top().first >= nums[i]){ 
                while(!st.empty() && st.top().first >= nums[i]){
                    st.pop();
                }
                if(st.size()==0) ans.push_back(psuedo);
                else ans.push_back(st.top().second);
            }
            st.push({nums[i],i});
        }
        return ans;

    }
    vector<int> findRight (vector<int>& nums){
        stack<pair<int,int>> st;
        vector<int> ans;
        int psuedo = nums.size();

        for(int i =nums.size()-1;i>=0;i--){
            if(st.empty()) ans.push_back(psuedo);

            else if(!st.empty() && st.top().first < nums[i]) ans.push_back(st.top().second);
            else if(!st.empty() && st.top().first >= nums[i]){ 
                while(!st.empty() && st.top().first >= nums[i]){
                    st.pop();
                }
                if(st.size()==0) ans.push_back(psuedo);
                else ans.push_back(st.top().second);
            }
            st.push({nums[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> left = findLeft(heights);
        vector<int> right = findRight(heights);

        vector<int> ans;

        for(int i =0;i<heights.size();i++){
            int x = (heights[i]) * (right[i]-left[i]-1);
            ans.push_back(x);
        }

        return *max_element(ans.begin(),ans.end());
        
    }
};