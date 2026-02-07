class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> number_of_a(n, 0);
        vector<int> number_of_b(n, 0);
        int ans = INT_MAX;

        for (int i = 1; i < n; i++) {

            if (s[i - 1] == 'b') {
                number_of_b[i] = number_of_b[i - 1] + 1;
            } else {
                number_of_b[i] = number_of_b[i - 1];
            }
        }

        for (int i = n - 2; i >= 0; i--) {

            if (s[i + 1] == 'a') {
                number_of_a[i] = number_of_a[i + 1] + 1;
            } else {
                number_of_a[i] = number_of_a[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {

            ans = min(ans, (number_of_b[i] + number_of_a[i]));
        }

        return ans;
    }
};