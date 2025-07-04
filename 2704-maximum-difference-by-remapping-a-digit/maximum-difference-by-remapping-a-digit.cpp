class Solution {
private:
    int findMaxi(int num) {
        string up = to_string(num);

        int n = up.size();

        char org;

        for (int i = 0; i < n; i++) {
            if (up[i] == '9') {
                continue;
            } else {
                org = up[i];
                up[i] = '9';
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (up[i] == org) {
                up[i] = '9';
            }
        }

        return stoi(up);
    }

    int findMini(int num) {
        string low = to_string(num);

        int n = low.size();

        char org;

        for (int i = 0; i < n; i++) {
            if (low[i] == '0') {
                continue;
            } else {
                org = low[i];
                low[i] = '0';
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (low[i] == org) {
                low[i] = '0';
            }
        }

        return stoi(low);
    }

public:
    int minMaxDifference(int num) {

        int a = findMaxi(num);
        int b = findMini(num);

        return a - b;
    }
};