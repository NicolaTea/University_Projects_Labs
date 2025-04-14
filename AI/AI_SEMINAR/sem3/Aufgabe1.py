import heapq
import numpy as np
import math


def distance(x, y):
    return math.sqrt((((x[0] - y[0])) ** 2 + ((x[1] - y[1]) ** 2)))


class Map:
    def __init__(self, m: np.ndarray) -> None:
        self.m = m

    def neighbors(self, cell):
        nrow, ncol = m.shape
        x, y = cell
        nb = []
        if x > 0:
            if m[x - 1, y] == 0:
                nb = nb + [(x - 1, y)]
        if x < (nrow - 1):
            if m[x + 1, y] == 0:
                nb = nb + [(x + 1, y)]
        if y > 0:
            if m[x, y - 1] == 0:
                nb = nb + [(x, y - 1)]
        if y < (ncol - 1):
            if m[x, y + 1] == 0:
                nb = nb + [(x, y + 1)]
        return nb


m = np.array(
    [[0, 1, 0, 0, 0, 0, 0], [0, 1, 0, 1, 0, 0, 1], [0, 1, 0, 1, 0, 1, 0], [0, 1, 0, 1, 0, 0, 0], [0, 0, 0, 1, 1, 0, 0],
     [0, 0, 0, 1, 1, 0, 0]])
mm = Map(m)
mm.neighbors((4, 1))

class PriorityQueue:
    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def put(self, item, priority):
        heapq.heappush(self.elements, (priority, item))

    def get(self):
        return heapq.heappop(self.elements)[1]


class Stack:
    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def put(self, x):
        self.elements.append(x)

    def get(self):
        return self.elements.pop()


def dfs(map : Map,start,goal):
    #TODO
    frontier = Stack()
    frontier.put(start)
    came_from = {start: None}
    while not frontier.empty():
        current=frontier.get()
        if current==goal:
            return came_from
        nn=map.neighbors(current)
        for n in nn:
            if n not in came_from:
                frontier.put(n)
                came_from[n]=current
    return came_from #goal not found

def make_path(came_from,start,goal):
    #TODO
    path=[goal]
    nex=came_from[goal]
    while nex!=start:
        path.append(nex)
        nex=came_from[nex]
    path.reverse()
    return [start]+path


def astar(map: Map, start, goal):
    # TODO
    pq = PriorityQueue()
    pq.put(start, 0)
    came_from = {start: None}
    cost_so_far = {start: 0}
    while not pq.empty():
        current = pq.get()
        if current == goal:
            return make_path(came_from, start, goal)
        for neighbor in map.neighbors(current):
            new_cost = cost_so_far[current] + 1
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                priority = new_cost + distance(neighbor, goal)
                pq.put(neighbor, priority)
                came_from[neighbor] = current

    return None


came_from_dfs = dfs(mm, (0,0), (5,6))
path_dfs = make_path(came_from_dfs, (0,0), (5,6))
print("DFS Path:", path_dfs)


path_astar = astar(mm, (0,0), (5,6))
print("A* Path:", path_astar)