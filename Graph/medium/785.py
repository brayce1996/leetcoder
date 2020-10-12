"""
# 詳細思路

## 題目：可否把圖切成兩個group A, B
使得圖中的每個edge的兩端都有連到A和B的node?

## 嘗試
```
True:
0 ---- 1

True:
0 ---- 1 ---- 2

True:
0 ---- 1 ---- 2
|
3
```
: 如果一個node的degree為1，則可以無視該node，因為必定能夠達成bipartite
: 只需考慮degree > 1的部分

```
False:
0 ---- 1
  \       /
	  \   /
		 2

```
: 若想把2跟0切割成不同組，**則不能存在一個同時連接2和0的node**
: 在這個圖裡面找不到，所以false
:: **相連的兩點一定在不同group，才能構成bipartite**

::: 我可以隨便挑相連的兩點，將他們切成兩個group，然後開始審查其他的能否加入其中一個group，若失敗，代表無法構成bipartite。若全部的點都能分配到其中一個group，則成功。

更general的審查法：
檢查一個node有沒有同時連接到兩個group (set)
: 所以用UnionFind的方式來處理似乎不錯??

如何決定下一個要審查的點？
: 從已經被分配進入任一group的node的neighbor開始，直到沒有未加入的neighbor

兩個group的所有neighbor都加入以後，就結束了嗎？
: no，可能會有完全不相連的nodes
```
Ex:
0 --- 1

2 --- 3

```

## 構思更簡單的審查順序：
由於**相連的兩點一定在不同group**，
一個node的neighbor的neighbor則必定屬於同一個group
: 可用BFS的方式來檢查，當前level與下一level的nodes屬於不同group。若在屬於group A的level遇到已經visited的node，且該node之前是在group B的level visited，代表違規（失敗），無法構成bipartite
"""

import queue
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        if len(graph) == 0:
            return True
        
        groupA = set()
        groupB = set()
        
        startNode = 0
        
        while len(groupA) + len(groupB) < len(graph):
            q = queue.Queue()
            
            # try to find unvisited node
            while startNode in groupA or startNode in groupB:
                startNode += 1
            
            # setup start node
            q.put(startNode)
            groupA.add(startNode)

            print(startNode)
            level = 0
            while not q.empty():
                nextQ = queue.Queue()

                # even level
                currGroup = groupA
                otherGroup = groupB
                if level % 2 == 1:
                    # odd level
                    currGroup = groupB
                    otherGroup = groupA

                while not q.empty():
                    currNode = q.get()
                    for neighbor in graph[currNode]:
                        if neighbor in currGroup:
                            return False
                        elif neighbor not in otherGroup:
                            otherGroup.add(neighbor)
                            nextQ.put(neighbor)

                level += 1
                q = nextQ
                
            
        return True
