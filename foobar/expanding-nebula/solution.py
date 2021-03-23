from time import time

def rotate(g):
    # Rotates grid for easier indexing for columns.
    n, m = len(g[0]), len(g)
    ng = [[0 for i in xrange(m)] for j in xrange(n)]
    for i in xrange(n):
        for j in xrange(m):
            ng[i][j] = g[j][i]
    return ng

def pre(col): # Finds the possible previous states of the two columns that become col after one time step.
    n = len(col)
    pos = [[[0,0]],[[1,0]],[[0,1]]] # list of possibles. this initial list is for the top row
    if col[0] == 0:
        pos.append([[1,1]]) # special case for top row if the first element in column is 0
    for i in xrange(n):
        newpos = []
        for p in pos:
            if col[i]:
                # cell contains gas
                c = p[i].count(1) # counts the number of cells above with gases.
                if c == 1:
                    # there must only be one cell with gas, so the rest must be zero
                    newpos.append(p + [[0,0]])
                elif c == 0:
                    # if there's no gas in the cells above, then there must be gas in one of the cells below
                    newpos.append(p + [[0,1]])
                    newpos.append(p + [[1,0]])
                # we don't add anything if there are two cells above containing gas
                # because it's impossible for a cell to contain gas if the previous state had multiple cells containing gases
            else:
                # cell does not contain gas
                c = p[i].count(1)
                # adding two cells with gases is always ok if result must be a cell without gas
                newpos.append(p + [[1,1]]) # it's always valid to add two cells with gas
                if c == 0:
                    # case where there are no cells containing gas at all
                    newpos.append(p + [[0,0]])
                else:
                    # if at least one cell above contains gas, it's ok to add two cells with one of them containing gas
                    newpos.append(p + [[0,1]])
                    newpos.append(p + [[1,0]])
                    if c == 2:
                        # if both cells have gases above, then it is possible to add 2 cells with no gas
                        newpos.append(p + [[0,0]])
        pos = newpos
    # columns will be converted to binary integers from here on
    # so instead of [True, False, True], we just use 101 in binary
    # given the contraints, the resulting binary number will fit 32-bit integers
    ans = dict() # left column mapped to their corresponding valid right columns
    n = len(pos[0]) # a and b will always be at most n bits long
    for p in pos:
        a, b = 0, 0
        for i in xrange(n):
            a *= 2 # shift left
            b *= 2
            a += p[i][0] # add bit at end
            b += p[i][1]
        if a in ans:
            ans[a].append(b)
        else:
            ans[a] = [b]
    return ans

def solution(g):
    # we can probably do the rotation locally, but it's clearer this way
    g = rotate(g)
    ans = dict()
    n = len(g)
    # priming ans using values from pre(g[0])
    # instead of iterating from 0 to 2 ** n - 1
    # because n can reach 50 max
    p = pre(g[0])
    for v in p.values():
        for i in v:
            if i in ans:
                ans[i] += 1
            else:
                ans[i] = 1
    for c in xrange(1, n): # iterating over the columns
        tmp = dict()
        p = pre(g[c])
        for key in ans:
            # check if the right column can be continued
            if key in p:
                vals = p[key]
                for v in vals:
                    if v in tmp:
                        tmp[v] += ans[key]
                    else:
                        tmp[v] = ans[key]
        ans = tmp
    return sum(ans.values())

def test_cases():
    inputs = [
        [
            [True, False, True],
            [False, True, False],
            [True, False, True]
        ],
        [
            [True, True, False, True, False, True, False, True, True, False],
            [True, True, False, False, False, False, True, True, True, False],
            [True, True, False, False, False, False, False, False, False, True],
            [False, True, False, False, False, False, True, True, False, False]
        ],
        [
            [True, False, True, False, False, True, True, True],
            [True, False, True, False, False, False, True, False],
            [True, True, True, False, False, False, True, False],
            [True, False, True, False, False, False, True, False],
            [True, False, True, False, False, True, True, True]
        ]
    ]
    outputs = [4, 11567, 254]
    n = len(inputs)
    for i in xrange(n):
        ret = solution(inputs[i])
        assert ret == outputs[i], "Test Case Failed.\nInput: {}\nOutput: {}\nExpected: {}".format(inputs[i], ret, outputs[i])

if __name__ == "__main__":
    start = time()
    test_cases()
    end = time()
    print "Time elapsed: {}".format(end - start)
