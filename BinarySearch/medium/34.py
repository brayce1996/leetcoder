"""
Naive:
binary search to find target in nums, cost O(logn)

then linear reach out the left and right end of target, cost O(n) at worst case


Improvement:
how about find target+0.5 and target-0.5?


edge cases:
1. nums:[1,1,1], t: 1

"""


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binarySearch(t):
            low = 0
            high = len(nums) - 1

            while low <= high:
                mid = (low + high) // 2
                if nums[mid] < t:
                    low = mid + 1
                elif nums[mid] > t:
                    high = mid - 1

            return high

        leftTarget = target - 0.5
        rightTarget = target + 0.5

        left = binarySearch(leftTarget) + 1
        right = binarySearch(rightTarget)
        return [left, right] if left <= right else [-1, -1]
