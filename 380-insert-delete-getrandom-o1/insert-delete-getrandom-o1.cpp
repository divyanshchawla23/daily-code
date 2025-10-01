class RandomizedSet {
public:
    set<int> st;
    map<int, int> mpp;
    RandomizedSet() {}

    bool insert(int val) {
        if (mpp.find(val) != mpp.end()) {
            return false;
        } else {

            mpp[val] = 1;
            st.insert(val);

            return true;
        }
    }

    bool remove(int val) {
        if (mpp.find(val) == mpp.end()) {
            return false;
        } else {

            mpp.erase(val);
            st.erase(val);

            return true;
        }
    }

    int getRandom() {
        int idx = rand() % st.size(); // pick a random index
        auto it = st.begin();
        advance(it, idx); // move iterator idx steps forward
        return *it;       // return that element
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */