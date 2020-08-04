class Solution {
public:
    int numTrees(int n) {
        if (n < 1) return 0;
        
        vector<int> mem(n + 1, 0);
        return helper(n, mem);
    }
    
    int helper(int n, vector<int> &mem) {
        if (n <= 1) return 1;
        if (mem[n] != 0) return mem[n];
        
        int count = 0;
        for (int i = 1; i <= n; i += 1) {
            count += helper(i - 1, mem) * helper(n - i, mem);
        }
        
        mem[n] = count;
        return count;
    }
};
