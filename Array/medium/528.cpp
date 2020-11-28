class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        srand(time(NULL));
        int sum = 0;
        for (int weight: w) {
            sum += weight;
            prefixSum.push_back(sum);
        }
    }

    int pickIndex() {
        int randMax = prefixSum.back();
        int pick = rand() % randMax + 1;

        // binary search the interval where pick rest
        int low = 0;
        int high = prefixSum.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (prefixSum[mid] < pick) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
