#!/usr/bin/pypy

from copy import deepcopy

def pre(m):
    n = len(m)
    for i in xrange(n):
        for j in xrange(n):
            for k in xrange(n):
                m[i][j] = min(m[i][j], m[i][k] + m[k][j])
                # minimize decrease in time
    for i in xrange(n):
        if m[i][i] < 0:
            return True, m
    return False, m

class State:
    def __init__(self, pos, time, path, avoid):
        self.pos = pos
        self.time = time
        self.path = path
        self.avoid = avoid
        # avoid: edge list that stores edges to avoid to prevent looping

def solution(times, time_limit):
    n = len(times)
    loopfound, optimes = pre(times)
    if loopfound:
        # we can loop till we have enough time to rescue them all
        return list(xrange(n - 2))
    ans = set()
    st = [State(0, time_limit, [0], [[i] for i in xrange(n)])]
    while st:
        cur = st.pop()
        possibles = [i for i in xrange(n) if i not in cur.avoid[cur.pos]]
        for nxt in possibles:
            tnxt = optimes[cur.pos][nxt]
            tback = optimes[nxt][cur.pos]
            tesc = optimes[nxt][-1]
            newavoid = deepcopy(cur.avoid)
            newtime = cur.time - tnxt
            newpath = cur.path + [nxt]
            if tnxt + tback == 0:
                # avoid repetition later
                newavoid[nxt].append(cur.pos)
                newavoid[cur.pos].append(nxt)
            if cur.time - tnxt - tesc >= 0:
                st.append(State(nxt, newtime, newpath, newavoid))
                if nxt == n - 1: # reached bulkhead
                    tmp = set(newpath)
                    if len(tmp) == n:
                        # if we have all bunnies (while we are in bulkhead)
                        return list(xrange(n - 2))
                    if len(tmp) > len(ans) or (len(tmp) == len(ans) and sum(tmp) < sum(ans)):
                        ans = tmp
    return sorted([x - 1 for x in ans if 0 < x < n - 1])

print solution([
    [0, 2, 2, 2, -1],
    [9, 0, 2, 2, -1],
    [9, 3, 0, 2, -1],
    [9, 3, 2, 0, -1],
    [9, 3, 2, 2, 0]],
    1)

assert (solution([
    [0, 2, 2, 2, -1],
    [9, 0, 2, 2, -1],
    [9, 3, 0, 2, -1],
    [9, 3, 2, 0, -1],
    [9, 3, 2, 2, 0]],
    1) == [1, 2])

assert (solution([
    [0, 1, 1, 1, 1],
    [1, 0, 1, 1, 1],
    [1, 1, 0, 1, 1],
    [1, 1, 1, 0, 1],
    [1, 1, 1, 1, 0]],
    3) == [0, 1])

print 'all test cases passed'
