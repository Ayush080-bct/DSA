import math


G={
   'A':{'C':9,'B':4},
   'B':{'A':4,'C':1,'D':2},
   'C':{'A':9,'B':1,'E':5,'D':3},
   'D':{'E':3,'C':3,'B':2,'F':7},
   'E':{'C':5,'F':1,'D':3},
   'F':{'E':8,'D':7}
   }
def find(set, vertex):
    if set[vertex] != vertex:
        set[vertex] = find(set, set[vertex])
    return set[vertex]
def union(set, u, v):
    root_u = find(set, u)
    root_v = find(set, v)
    set[root_v] = root_u

def krushkal(G):
    
    mst = [] 
    set = {}
    for vertex in G:
        set[vertex] = vertex
    edges = []
    for u in G:
        for v in G[u]:
            if (v, u, G[u][v]) not in edges:
                edges.append((u, v, G[u][v]))
    edges.sort(key=lambda edge: edge[2])
    for u, v, cost in edges:
        if find(set, u) != find(set, v):  
            mst.append((u, v, cost))  
            union(set, u, v)        

    return mst

mst=krushkal(G)
print("Minimum Spanning Tree:")
for u, v, cost in mst:
    print(f"{u} - {v} (weight: {cost})")




