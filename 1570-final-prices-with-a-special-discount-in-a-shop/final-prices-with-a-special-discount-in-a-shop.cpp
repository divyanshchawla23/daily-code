class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        stack<int> st;
        vector<int> ans ;

        for(int i = arr.size()-1;i>=0;i--){

            if(st.size()==0) ans.push_back(arr[i]);
            
            else if (!st.empty() && st.top()<=arr[i]){
                ans.push_back(arr[i]- st.top());
            }

            else if (!st.empty()&&st.top()>arr[i]){
               
                 
                while(!st.empty()&&st.top()>arr[i]){
                    st.pop();
                }
                if(st.size()==0) ans.push_back(arr[i]);

                else{
                    ans.push_back(arr[i]-st.top());
                }

            }

            st.push(arr[i]);



        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};