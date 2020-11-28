class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.kvStore = defaultdict(list)


    def set(self, key: str, value: str, timestamp: int) -> None:
        self.kvStore[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.kvStore or self.kvStore[key][0][0] > timestamp:
            return ""

        low, high = 0, len(self.kvStore[key]) - 1

        while (low < high):
            mid = (low + high + 1) // 2
            if self.kvStore[key][mid][0] == timestamp:
                return self.kvStore[key][mid][1]
            elif self.kvStore[key][mid][0] > timestamp:
                high = mid - 1
            else:
                low = mid
        return self.kvStore[key][low][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
