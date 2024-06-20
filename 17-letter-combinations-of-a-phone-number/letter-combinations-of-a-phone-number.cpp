class Solution {
public:
    void help(string &digits , int index, map<int ,vector <char>> &mpp,string curr , vector<string> &res){
        if(index>=digits.size()){
            res.push_back(curr);
            return ;
        }

        for(auto it : mpp[digits[index]-'0']){
            help(digits ,  index+1, mpp,curr+it, res);
        }


        
        

    }

    vector<string> letterCombinations(string digits) {
        if (digits.size()==0){
            return{} ;
        }
        vector<string> res;
        string curr;

        map<int , vector <char>> mpp;
        mpp[2]={'a','b','c'};
        mpp[3]={'d','e','f'};
        mpp[4]={'g','h','i'};
        mpp[5]={'j','k','l'};
        mpp[6]={'m','n','o'};
        mpp[7]={'p','q','r','s'};
        mpp[8]={'t','u','v'};
        mpp[9]={'w','x','y','z'};


         help(digits ,  0, mpp,curr, res);
        return res ;
    }
};