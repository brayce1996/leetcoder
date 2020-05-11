class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> abSumCount;
        for (int a: A) {
            for (int b: B) {
                int sum = a+b;
                abSumCount[sum] += 1;
            }
        }
        
        int count = 0;
        for (int d: D) {
            for (int c: C) {
                count += abSumCount[-(d + c)];
            }
        }
        return count;
    }
};