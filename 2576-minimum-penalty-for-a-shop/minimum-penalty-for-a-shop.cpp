class Solution {
public:
    int bestClosingTime(string cc) {
        int n = cc.size();
        vector<int> pref(n + 1, 0);
        vector<int> suff(n + 1, 0);
        pref[0] = 0;
        suff[n] = 0;

        for (int i = 1; i <= n; i++) {
            if (cc[i - 1] == 'N') {
                pref[i] = pref[i - 1] + 1;
            } else {
                pref[i] = pref[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (cc[i] == 'Y') {
                suff[i] = suff[i + 1] + 1;
            } else {
                suff[i] = suff[i + 1];
            }
        }

        int min_pen = INT_MAX;
        int min_time = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int pen = pref[i] + suff[i];

            if (pen < min_pen) {
                min_pen = pen;
                min_time = i;
            }
        }
        return min_time;
    }
};