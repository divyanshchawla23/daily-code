class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>> bids;
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>>>
        userToItemAndBid;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {

        bids[itemId][userId] = bidAmount;
        userToItemAndBid[itemId].push({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        bids[itemId][userId] = newAmount;
        userToItemAndBid[itemId].push({newAmount, userId});
    }

    void removeBid(int userId, int itemId) { bids[itemId].erase(userId); }

    int getHighestBidder(int itemId) {
        auto& it = userToItemAndBid[itemId];
        if (it.empty())
            return -1;

        auto& pq = userToItemAndBid[itemId];

        while (!pq.empty()) {
            auto [amount, userId] = pq.top();

            // valid only if it matches current bid
            if (bids[itemId].count(userId) && bids[itemId][userId] == amount) {
                return userId;
            }

            pq.pop(); // stale entry
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */