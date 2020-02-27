// from 907
// increase monotone stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        // 用increase monotone stack取得前一個較小值(previous less element)、下一個較小值(next less element)的位置(index)
        // 1. incStack內的index所指到的heights[index]數字必定遞增
        // 2. 在incStack內的index都是還未找到NLE的height的index
        stack<int> incStack;
        // prevLessIndex紀錄各個height[i]對應到的PLE的位置, 若無PLE預設為-1
        vector<int> prevLessIndex(size, -1);
        // nextLessIndex紀錄各個height[i]對應到的NLE的位置, 若無NLE預設為size
        vector<int> nextLessIndex(size, size);

        // 求取並記錄heights內每個element的PLE, NLE
        for (int i = 0; i < size; i++) {
            // 當遇到一個heigt比incStack.top小時，代表遇到top的NLE了
            while(!incStack.empty() && heights[incStack.top()] > heights[i]) {
                int index = incStack.top();
                nextLessIndex[index] = i; // 紀錄stack top的NLE
                incStack.pop();
            }

            // 當while迴圈結束，代表stack已空或是遇到的stack top已經比heights[i]小了
            // 這同時也代表找到heights[i]的PLE
            prevLessIndex[i] = (incStack.empty())? -1 : incStack.top();
            
            // 加入stack等待尋找NLE
            incStack.push(i);
        }
        
        // 利用每個heights[index]對應到的NLE, PLE之index，可以計算出該height及index的最佳解寬度(width)
        // width*height就是該index的最佳解
        // 在此用迴圈找出所有最佳解中最大的值，即為答案
        int maxRectArea = 0;
        for (int i = 0; i < size; i++) {
            int width = nextLessIndex[i] - prevLessIndex[i] - 1;
            int area = width * heights[i];
            if (area > maxRectArea) maxRectArea = area;
        }
        return maxRectArea;
    }
};
