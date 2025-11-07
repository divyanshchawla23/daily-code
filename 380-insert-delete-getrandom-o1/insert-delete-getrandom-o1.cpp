class RandomizedSet {
public:
    vector<int> v;
    map<int, int> mpp;
    RandomizedSet() {}

    bool insert(int val) {
        if (mpp.find(val) != mpp.end()) {
            return false;
        }
        v.push_back(val);
        mpp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mpp.find(val) == mpp.end()) {
            return false;
        }

        int ind = mpp[val];

        int lastEl = v.back();
        mpp[lastEl]=ind;

        v[ind] = lastEl;

        v.back() = val;
        
        v.pop_back();
        mpp.erase(val);

        return true;
    }

    int getRandom() {
        int randomInd = rand() % v.size();
        return v[randomInd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */