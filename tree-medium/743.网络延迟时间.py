#
# @lc app=leetcode.cn id=743 lang=python3
#
# [743] 网络延迟时间
#
import heapq
import collections
from typing import List


# @lc code=start
class Solution:
    # def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
    #     graph = [[] for _ in range(N + 1)]
    #     costs = dict()
    #     inf = 1 << 31
    #     arrived = [inf] * (N + 1)
    #     for time in times:
    #         graph[time[0]].append(time[1])
    #         costs[(time[0], time[1])] = time[2]

    #     def dfs(fr: int, to: int):
    #         arrived[to] = min(arrived[to], arrived[fr] + costs[(fr, to)])
    #         for i in graph[to]:
    #             if arrived[to] == inf or arrived[to] + costs[(to, i)] < arrived[i]:
    #                 dfs(to, i)

    #     arrived[K] = 0
    #     for i in graph[K]:
    #         dfs(K, i)

    #     return max(arrived[1:]) if inf not in arrived[1:] else -1

    # up grade
    # def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
    #     graph = collections.defaultdict(list)
    #     for u, v, w in times:
    #         graph[u].append((w, v))
    #     dist = {i: float('inf') for i in range(1, N+1)}

    #     def dfs(node: int, cost: int):
    #         if cost >= dist[node]:
    #             return
    #         dist[node] = cost
    #         for time, to in sorted(graph[node]):
    #             dfs(to, cost + time)

    #     dfs(K, 0)
    #     ret = max(dist.values())
    #     return ret if ret < float('inf') else -1

    # Dijkstra's
    # def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
    #     graph = collections.defaultdict(list)
    #     for u, v, w in times:
    #         graph[u].append((v, w))
    #     dist = {i: float('inf') for i in range(1, N+1)}
    #     visited = set()
    #     dist[K] = 0
    #     while True:
    #         candidate_node, candidate_dist = -1, float('inf')
    #         for i in range(1, N+1):
    #             if i not in visited and dist[i] < candidate_dist:
    #                 candidate_node, candidate_dist = i, dist[i]

    #         if candidate_node < 0:
    #             break
    #         visited.add(candidate_node)
    #         for node, time in graph[candidate_node]:
    #             dist[node] = min(dist[node], dist[candidate_node] + time)
    #     ret = max(dist.values())
    #     return ret if ret < float('inf') else -1

    # heap
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))
        pq = [(0, K)]
        dist = dict()
        while pq:
            time, node = heapq.heappop(pq)
            if node in dist:
                continue
            dist[node] = time
            for v, w in graph[node]:
                if v not in dist:
                    heapq.heappush(pq, (time + w, v))

        return max(dist.values()) if len(dist) == N else -1


# @lc code=end
print(Solution().networkDelayTime([[1, 2, 1], [2, 1, 3]], 2, 2))
# [[1, 2, 1], [2, 1, 3]]\n2\n2
# [[1,2,1],[2,3,2],[1,3,4]]\n3\n1
