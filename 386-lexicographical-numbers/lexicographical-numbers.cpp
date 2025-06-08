class Solution {
private:
    void f(int i, int n , vector<int>& ans){
        if(i>n) return;
        ans.push_back(i);
        for(int num =0;num<=9;num++){
            int newNumber = (i*10) + num;
            if(newNumber>n) return;
            f(newNumber,n,ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i =1;i<=9;i++){
            f(i,n,ans);
        }
        return ans;
    }
};