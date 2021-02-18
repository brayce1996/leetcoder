class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        def binarySearchLargerMin(target):
            low, high = 0, len(incList)-1

            while low <= high:
                mid = (low + high) // 2
                if incList[mid] == target:
                    return mid
                elif incList[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
            return low

        incList = [nums[0]]
        for num in nums:
            if num > incList[-1]:
                incList.append(num)
            else:
                idx = binarySearchLargerMin(num)
                incList[idx] = num

        return len(incList)

"""
最難解釋的就是 line 21 ~ 22

可以看exmaple來理解
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

用 discard 的概念可以更清楚的解釋為何 line 22 的 replace 可以引導到答案
discard 代表目前有更好的 increasing 組合了
而 line 22 的 replace 只是為了省空間複雜度的手段

所以也許從 discard 的概念開始解釋思路會比較清楚
等概念表達清楚後，再往 replace 的方向去優化
"""
