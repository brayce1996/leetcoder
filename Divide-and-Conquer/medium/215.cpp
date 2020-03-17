class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        mergeSort(nums);
        return nums[nums.size() - k];
    }

    // in-place
    void mergeSort(vector<int>& arr) {
        if (arr.size() == 1) return;

        int mid = arr.size() / 2;
        
        // divid
        vector<int> leftList(arr.begin(), arr.begin() + mid);
        vector<int> rightList(arr.begin() + mid, arr.end());
        mergeSort(leftList);
        mergeSort(rightList);

        // conquer (merge)
        int leftIndex = 0;
        int rightIndex = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (leftIndex >= leftList.size()) {
                arr[i] = rightList[rightIndex];
                rightIndex++;
            } else if (rightIndex >= rightList.size()) {
                arr[i] = leftList[leftIndex];
                leftIndex++;
            } else {
                if (rightList[rightIndex] > leftList[leftIndex]) {
                    arr[i] = leftList[leftIndex];
                    leftIndex++;
                } else {
                    arr[i] = rightList[rightIndex];
                    rightIndex++;
                }
            }
        }
    }
};
