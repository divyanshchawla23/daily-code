class Solution {
private:
    bool isPrime(int n) {
        if (n < 2)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    vector<bool> getmeThis(int right) {
        vector<bool> help;
        for (int i = 0; i <= right; i++) {
            if (isPrime(i)) {
                help.push_back(true);
            } else
                help.push_back(false);
        }
        return help;
    }

public:
    vector<int> closestPrimes(int left, int right) {

        int diff = INT_MAX;
        vector<int> ans = {-1, -1};
        vector<bool> all = getmeThis(right);
        

        vector<int> primes;
        for(int i=left;i<=right;i++){
            if(all[i]==true){
                primes.push_back(i);
            }
        }

        for(int i =1;i<primes.size();i++){
            if(primes[i]-primes[i-1]<diff){
                diff = primes[i]-primes[i-1];
                ans[0]=(primes[i-1]);
                ans[1]=(primes[i]);
            }
        }

        return primes.size() < 2 ? vector<int>{-1, -1} : ans;
    }
};