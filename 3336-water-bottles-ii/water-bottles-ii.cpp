class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottle = numBottles;
        

        while(emptyBottle>=numExchange){
            emptyBottle -= numExchange;
            ans+=1;
            emptyBottle++;
            numExchange++;
        }

        return ans;
    }
};