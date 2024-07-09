class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int totalTime = customers[0][0] + customers[0][1];
        double waitingTime = customers[0][1];
        for(int i=1; i<customers.size(); i++) {
            if(customers[i][0] > totalTime) {
                totalTime = customers[i][0];
            }
            totalTime += customers[i][1];
            waitingTime += (totalTime - customers[i][0]);
        }
        return (waitingTime/customers.size());
    }
};