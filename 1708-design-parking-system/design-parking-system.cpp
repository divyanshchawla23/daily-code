class ParkingSystem {
public:
    int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a=big;
        b=medium;
        c=small;
    }
    
    bool addCar(int carType) {
        
        if(carType == 1)
        {
            if(a==0) return false;
            a--;
        }
        else if(carType == 2)
        {
            if(b==0) return false;
            b--;
        }
        else if(carType == 3)
        {
            if(c==0) return false;
            c--;
        }
        return true;
    }

    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */