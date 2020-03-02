class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 1) return -1;
        // search pivot
        int jumpDist = size / 2;
        int currIndex = 0;
        int nextIndex = currIndex + jumpDist;
        if (nums[0] > nums[size - 1]) {
            while (true) {
                cout << "c: " << currIndex << ", n: " << nextIndex << endl;
                jumpDist = ceil((double)jumpDist / 2);
                if (nums[currIndex] < nums[nextIndex]) {
                    currIndex = nextIndex;
                    nextIndex = currIndex + jumpDist;
                } else {
                    currIndex = nextIndex;
                    nextIndex = currIndex - jumpDist;
                }
                
                if (nums[currIndex - 1] > nums[currIndex]) break; // found
            };
        }
        int shift = currIndex;
        cout << currIndex << endl;
        
        
        // search target
        int leftBound = shift;
        int rightBound = size - 1 + shift;
        int guessIndex = ((int)ceil((double)(leftBound + rightBound) / 2)) % size;
        
        while (true) {
            cout << "l: "<<leftBound << ", g: " << guessIndex << ", r: " << rightBound<<endl;
            if (leftBound > rightBound ) return -1;

            if (nums[guessIndex] == target) {
                break;
            } else if (nums[guessIndex] > target) {
                rightBound = (guessIndex >= shift)? guessIndex - 1 : guessIndex + size - 1 ;
            } else {
                leftBound = (guessIndex >= shift)? guessIndex + 1 : guessIndex + size + 1;
            }
            guessIndex = ((int)ceil((double)(leftBound + rightBound) / 2)) % size;
        }
        return guessIndex;
    }
};
