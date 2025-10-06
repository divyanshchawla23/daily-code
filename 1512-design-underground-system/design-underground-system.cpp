class UndergroundSystem {
public:
    map<int,pair<string,int>> chkIn; // id -> station,t
    map<string,pair<int,int>> chkOut; // route -> time,peopleCnt
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chkIn[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = chkIn[id].first;
        int timeStart = chkIn[id].second;

        string route = startStation+"_"+stationName;

        int timeUsed = t - timeStart;


        chkOut[route].first += timeUsed;
        chkOut[route].second += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"_"+endStation;

        auto it = chkOut[route];

        return (double)it.first/it.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */