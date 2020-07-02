class Solution {
public:
    Solution(vector<int>& nums) {
        this->origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> copyOrigin(this->origin);
        int randomSize = copyOrigin.size();
        
        for (int i = 0; i < copyOrigin.size(); i++) {
            swap(copyOrigin[rand() % randomSize], copyOrigin[randomSize - 1]);
            randomSize -= 1;
        }
        
        return copyOrigin;
    }

private:
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */