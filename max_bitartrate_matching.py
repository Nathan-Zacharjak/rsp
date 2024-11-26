"""Given a bipartite, weighted, directed graph G with adjacency list N vertices by E edges,

Find the maximum possible flow between a given edge i and j,
given an input adjacency matrix 'G' as described above, into a function MaxFlow(G, source, sink),
that returns an integer representing the maximum possible flow between integers source and sink
representing vertices in graph G, and a 2d array of numbers representing the paths involved in
this max flow.


THEN, write a new function that uses the above function, to find the largest bipartite matching
of an *unweighted* graph
MaxBitartrateMatching(G, setA, setB) setA/B are arrays of integers
that contain the 2 bitartrate sets of vertices in G,
and returns an integer representing the maximum number of bitartrate matchings
between the 2 sets, and a 2d array representing each pair of matching vertices"""

# G = [{1: 1, 2: 2}, {3: 1}, {}]

class edge:
    end = -1
    capacity = -1
    # flow = -1
    # residual = -1

    # def __init__(self, end, capacity, flow, residual):
    def __init__(self, end, capacity):
        self.end = end
        self.capacity = capacity
        # self.flow = flow
        # self.residual = residual

    def __str__(self):
        return f"End:{self.end}, Capacity:{self.capacity}"

G = [[edge]]
G.append([edge(1,1), edge(2,2)])
G.append([edge(3,1)])
G.append([edge(3,2)])
G.append([])

for vertex, edges in enumerate(G):
    print(f"Vertex {vertex}:")
    for e in edges:
        print(e)


def MaxFlow(G, source, sink):
    return

# print(G)
# print(MaxFlow(G, 0, 2))
