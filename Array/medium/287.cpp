class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        // find intersection
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // go F steps, and meet at loop entry
        slow = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);
        
        return slow;
    }
};

// pigeonhole principle
// -> 一定有重複的數字
// -> 如果把每個element的值當作index，跳到下一個位置
//    一定會有loop
// loop的開始點就是重複的數字(有兩個以上的node指到它)


// slow: F + a
// fast: F + nC + a

// fast = slow * 2
// 2F + 2a = F + nC + a
// F + a = nC = slow = (n-1)*C + C
// F = (n-1)*C + C - a