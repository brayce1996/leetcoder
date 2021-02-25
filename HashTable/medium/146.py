"""
========= Code structure =============
get:
1. check if the key exist
    - if not, return -1
    - else
        1. update key-value pair to become least used
        2. return value by key

update:
1. check if the key exist
    - if not, then
    #
        1. insert key-value pair, and make it least used
        2. check if the capacity is exceeded
            - if so, then
                1. erase the last used key-value pair in the LRU cache
    - if exist, then
        1. update key-value pair to become least used
        2. update the value by key


========== Challenge ============
1. update key-value pair to become least used
2. erase the last used key-value pair in the LRU cache
3. manage key-value pair (insert/get/update)

========== Solution ============
3. use hashmap as cache, so the time complexity would be O(1) for insert/get/update operations

1., 2. use double-linked list to keep track of used ordering
1: delete one node from list, and insert it to the front of the list, O(1)
2. delete the last node of the list, O(1)

To locate a node,
I have to combine 3 with 1 and 2.
Map<int, &DoubleLinkedListNode>



OrderedDict is one implemenation for this purpose
OrderedDict stores items in the order keys that are last added
[last used ... least used]
                last_item
"""


class LRUCache:


    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = OrderedDict()

    def get(self, key: int) -> int:
        if key in self.map:
            # update key-value pair to become least used
            self.map.move_to_end(key)

            # return value by key
            return self.map[key]
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.map:
            # update key-value pair to become least used
            self.map.move_to_end(key)

            # update the value by key
            self.map[key] = value

        else:
            # insert key-value pair, and make it least used
            self.map[key] = value

            if len(self.map) > self.capacity:
                # erase the last used key-value pair in the LRU cache
                self.map.popitem(last=False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
