// from 907

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> incStack;
        vector<int> prevLessIndex(size, -1);
        vector<int> nextLessIndex(size, size);

        for (int i = 0; i < size; i++) {
            while(!incStack.empty() && heights[incStack.top()] > heights[i]) {
                int index = incStack.top();
                nextLessIndex[index] = i;
                incStack.pop();
            }
            prevLessIndex[i] = (incStack.empty())? -1 : incStack.top();
            incStack.push(i);
        }
        
        int maxRectArea = 0;
        for (int i = 0; i < size; i++) {
            int width = nextLessIndex[i] - prevLessIndex[i] - 1;
            int area = width * heights[i];
            if (area > maxRectArea) maxRectArea = area;
        }
        return maxRectArea;
    }
};
