class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3)
            return false;

        for (int i = 0; i < n; i++) {
            if (!isalnum(word[i]))
                return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;

        for (auto it : word) {
            char c = tolower(it);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                hasVowel = true;
            else if (isalpha(c))
                hasConsonant = true;
        }

        return hasVowel && hasConsonant;
    }
};
