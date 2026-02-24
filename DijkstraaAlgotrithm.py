import math
from queue import PriorityQueue
G={
    'A':{'B':6,'C':12},
    'B':{'A':6,'D':2,'E':3,'C':2},
    'C':{'B':2,'A':12,'D':6,'E':5},
    'D':{'C':6,'B':2},
    'E':{'C':5,'B':3}
}


def INITIALIZE_SINGLE_SOURCE(G, start_vertex):
    cost=dict()
    prev=dict()
    for vertex in G.keys():
        cost[vertex]=math.inf#infinity( 8 rotate(90 degree))
        prev[vertex]=" "
    cost[start_vertex]=0
    return cost,prev

def RELAX(G,u,v,cost,prev):
    if cost[v]>cost[u]+G[u][v]:
        cost[v]=cost[u]+G[u][v]
        prev[v]=u
    return cost,prev
def DJ(G,start_vertex):
    cost,prev=INITIALIZE_SINGLE_SOURCE(G,start_vertex)
    PQ= PriorityQueue()
    for vertex in G.keys():
        PQ.put((cost[vertex],vertex))
    visited=[]
    while(len(visited)!=len(G.keys())):
        _, currentvertex=PQ.get()
        visited.append(currentvertex)
        for chimeki in G[currentvertex].keys():
            if chimeki not in visited:
                cost,prev=RELAX(G,currentvertex,chimeki,cost,prev)
                PQ.put((cost[chimeki],chimeki))
    return cost,prev

def RECONSTRUCT_PATH(vertex, prev):
    path = vertex
    while prev[vertex] != " ":
        path = prev[vertex] + '->' + path
        vertex = prev[vertex]
    return path

start_vertex='A'
cost,prev=DJ(G,start_vertex)
for vertex in G.keys():
    print(f'Shortest Path From {start_vertex} to {vertex} is {RECONSTRUCT_PATH(vertex,prev)}')
    print(f'Cost is {cost[vertex]}')
    


