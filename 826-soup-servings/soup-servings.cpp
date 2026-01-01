class Solution {
public:
    double helper(double A, double B , vector<vector<int>> &turns, int n,vector<vector<double>> &dp){
        if(A<=0 && B<=0) return 0.5;
        if(A<=0) return 1.0;
        if(B<=0) return 0.0;

        if(dp[A][B]!=-1.0) return dp[A][B];

        double probab = 0.0;

        for(auto it: turns){
            int a_minus = it[0];
            int b_minus = it[1];

            probab += helper(A-a_minus,B-b_minus,turns,n,dp);
        }

        return dp[A][B] = 0.25 * probab;

    }
    double soupServings(int n) {
        if(n>=6000) return 1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.00));
        double A = (double)n;
        double B = (double)n;
        vector<vector<int>> turns;
        turns.push_back({100,0});
        turns.push_back({75,25});
        turns.push_back({50,50});
        turns.push_back({25,75});
        return helper(A,B,turns,n,dp);
    }
};