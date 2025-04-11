class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i =low;i<=high;i++){
            if(i>=10 && i<=99 && i % 11 == 0){
                ans++;
            }
            else if(i>=1000 && i<=9999){
                string str = to_string(i);
                int first = str[0];
                int second = str[1];
                int third= str[2];
                int fourth= str[3];

                if(first+second == fourth+third){
                    ans++;
                }

            }

        }
        return ans;
    }
};