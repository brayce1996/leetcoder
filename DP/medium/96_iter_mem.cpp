class Solution {
public:
    int numTrees(int n) {
        vector<int> mem(n + 1, 0);
        mem[0] = 1;
        mem[1] = 1;
        
        for (int i = 2; i <= n; i += 1) {
            for (int j = i / 2 + i % 2; j < i; j += 1) {
                mem[i] += 2 * mem[j] * mem[i - j - 1];
            }
            if (i & 1) {
                // i is odd
                mem[i] += mem[i / 2] * mem[i / 2];
            }
        }
        
        return mem[n];
    }
};
