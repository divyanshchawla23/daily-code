class FindSumPairs {
public:
    vector<int> a;
    vector<int> b;
    map<int,int> mpp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        for(auto &it : b){
            mpp[it]++;
        }
    }
    
    void add(int index, int val) {
        mpp[b[index]]--;
        b[index]+=val;
        mpp[b[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i =0;i<a.size();i++){
            int need = tot - a[i];
            if(mpp.find(need)!=mpp.end()){
                cnt+=mpp[need];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */