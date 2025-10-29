class Solution {
public:
    int smallestNumber(int n) {
        return ~0u>>__builtin_clz(n);
    }
};