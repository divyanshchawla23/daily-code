class Solution {
private:
    int digitSum(int n){
        int sum =0;
        while(n!=0){
            int lastDigit = n%10;
            sum = sum + lastDigit;
            n = n/10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        map<int , int> mpp;
        int maxSize =0;
        int cnt =0;

        
        for(int i = 1 ;i<=n;i++){
            int sumOfDigits = digitSum(i);

            mpp[sumOfDigits]++;

            if(mpp[sumOfDigits]==maxSize) cnt++;
            else if(mpp[sumOfDigits]>maxSize){
                maxSize = mpp[sumOfDigits];
                cnt = 1;
            }

        }
        return cnt;
    }
};