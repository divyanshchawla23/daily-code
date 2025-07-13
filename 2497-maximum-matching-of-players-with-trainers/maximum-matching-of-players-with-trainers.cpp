class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int cnt = 0;

        int i = 0;
        int j = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] > trainers[j]) {
                j++;
            } else {
                cnt++;
                i++;
                j++;
            }
        }

        return cnt;
    }
};