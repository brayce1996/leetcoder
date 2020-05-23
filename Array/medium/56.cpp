// Runtime: 40 ms, faster than 57.51% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.5 MB, less than 30.23% of C++ online submissions for Merge Intervals.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        
        int intervalIndex = 0;
        
        while (intervalIndex < intervals.size()) {
            // start from a new interval
            int startValue = intervals[intervalIndex][0];
            int boundValue = intervals[intervalIndex][1];
            
            // expand current interval
            while (intervalIndex < intervals.size() 
                   && intervals[intervalIndex][0] <= boundValue) {
                boundValue = max(boundValue, intervals[intervalIndex][1]);
                intervalIndex++;
            }
            
            vector<int> newInterval(2);
            newInterval[0] = startValue;
            newInterval[1] = boundValue;
            result.push_back(newInterval);
        }
            
        return result;
    }
};
