// from 907
// decrease monotone stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        stack<int> decStack; // stacking index of nums
        vector<int> nextGreater(size, -1);
        int firstMaxIndex = 0;
        
        for (int i = 0; i < size; i++) {
            if (nums[i] > nums[firstMaxIndex]) {
                firstMaxIndex = i;
            }
            while(!decStack.empty() && nums[decStack.top()] < nums[i]) {
                int x = decStack.top();
                nextGreater[x] = nums[i];
                decStack.pop();
            }
            decStack.push(i);
        }
        
        for (int i = 0; i <= firstMaxIndex; i++) {
            while(!decStack.empty() && nums[decStack.top()] < nums[i]) {
                int x = decStack.top();
                nextGreater[x] = nums[i];
                decStack.pop();
            }
        }
        
        return nextGreater;
    }
};
