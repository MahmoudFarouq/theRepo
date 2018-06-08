# Find Eulerian Tour
#
# Write a function that takes in a graph
# represented as a list of tuples
# and return a list of nodes that
# you would follow on an Eulerian Tour
#
# For example, if the input graph was
# [(1, 2), (2, 3), (3, 1)]
# A possible Eulerian tour would be [1, 2, 3, 1]

def rotate(ls):
    del ls[0]
    ls.append(ls[0])
    return ls

def find_eulerian_tour(graph):
    # your code here
    res = []
    res.append(graph[0][0]); res.append(graph[0][1]); del graph[0]
    while(len(graph) > 0):
        changed = False
        for i in range(len(graph)):
            if(graph[i][0] == res[-1]):
                res.append(graph[i][1])
                del graph[i]
                changed = True
                break
            elif(graph[i][1] == res[-1]):
                res.append(graph[i][0])
                del graph[i]
                changed = True
                break
        if (changed == False):
            res = rotate(res)
    return res


g = [(1, 13), (1, 6), (6, 11), (3, 13), (4, 11), 
     (0, 6),(5, 9), (2, 6), (6, 10), (7, 9),
     (1, 12), (4, 12), (5, 14), (0, 1), (2, 3),
     (7, 14), (10, 13), (9, 8), (8, 13), (6, 9)]

print( find_eulerian_tour(g) )
