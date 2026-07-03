from collections import deque
from math import inf

class Solution:
    def findMaxPathScore(self, edges, online, k):
        n = len(online)

        graph = [[] for _ in range(n)]
        indegree = [0] * n
        costs = set()

        for u, v, c in edges:
            graph[u].append((v, c))
            indegree[v] += 1
            costs.add(c)

        # Topological sort
        q = deque()
        temp = indegree[:]

        for i in range(n):
            if temp[i] == 0:
                q.append(i)

        topo = []
        while q:
            u = q.popleft()
            topo.append(u)

            for v, _ in graph[u]:
                temp[v] -= 1
                if temp[v] == 0:
                    q.append(v)

        costs = sorted(costs)

        def can(score):
            dist = [inf] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == inf:
                    continue

                for v, c in graph[u]:
                    if c < score:
                        continue

                    if v != n - 1 and not online[v]:
                        continue

                    new_cost = dist[u] + c
                    if new_cost < dist[v]:
                        dist[v] = new_cost

            return dist[n - 1] <= k

        left, right = 0, len(costs) - 1
        ans = -1

        while left <= right:
            mid = (left + right) // 2
            score = costs[mid]

            if can(score):
                ans = score
                left = mid + 1
            else:
                right = mid - 1

        return ans