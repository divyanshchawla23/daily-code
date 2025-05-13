class Solution {
    int M = 1e9 + 7; // Modulo value
public:
    int lengthAfterTransformations(string s, int t) {
        
        // Initialize the frequency array for characters 'a' to 'z'
        vector<int> mpp(26);
        for (char c : s) {
            mpp[c - 'a']++;
        }

        // Perform t transformations
        for (int i = 0; i < t; i++) {
            vector<int> temp(26, 0); // Temporary array to store transformed frequencies
            for (int j = 0; j < 26; j++) {
                int freq = mpp[j]; // Get the frequency of the current character
                if (j == 25) { // 'z' -> 'a' and 'b'
                    temp[0] = (temp[0] + freq) % M; // Add to 'a'
                    temp[1] = (temp[1] + freq) % M; // Add to 'b'
                } else {
                    temp[j + 1] = (temp[j + 1] + freq) % M; // Add to the next character
                }
            }
            mpp = temp; // Update mpp with the transformed frequencies
        }

        // Calculate the total length after all transformations
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            cnt = (cnt + mpp[i]) % M;
        }
        return cnt;
    }
};
