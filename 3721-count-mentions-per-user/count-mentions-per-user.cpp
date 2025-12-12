class Solution {
public:
    // static bool comp(const auto& v1, const auto& v2) {
    //     int t1 = stoi(v1[1]);
    //     int t2 = stoi(v2[1]);
    //     if (t1 == t2) {
    //         return v1[0] == "OFFLINE";
    //     }

    //     return t1 < t2;
    // }


    // CANT USE AUTO IN FUNCTIONS


    void util(vector<string>& event, vector<int>& ans,
              vector<int>& offlineTime) {

        int ts = stoi(event[1]);
        vector<string> id;

        stringstream ss(event[2]);
        string s;

        while (ss>>s) {
            id.push_back(s);
        }

        for (auto& it : id) {
            if (it == "ALL") {
                for (int i =0;i<ans.size();i++) {
                    ans[i]++;
                }
            } else if (it == "HERE") {
                for (int i =0;i<offlineTime.size();i++) {
                    if (offlineTime[i] == 0 || offlineTime[i] + 60 <= ts) {
                        ans[i]++;
                    }
                }
            } else {
                ans[stoi(it.substr(2))]++;
            }
        }
    }
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers);
        vector<int> offlineTime(numberOfUsers, 0);

        auto comp = [](const auto& v1, const auto& v2) {
            int t1 = stoi(v1[1]);
            int t2 = stoi(v2[1]);
            if (t1 == t2) {
                return v1[0] == "OFFLINE";
            }

            return t1 < t2;
        };

        sort(events.begin(), events.end(), comp);

        for (auto& it : events) {
            if (it[0] == "MESSAGE") {
                util(it, ans, offlineTime);
            } else {
                int ts = stoi(it[1]);
                int id = stoi(it[2]);
                offlineTime[id] = ts;
            }
        }

        return ans;
    }
};