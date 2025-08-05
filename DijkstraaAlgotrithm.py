import math
from queue import PriorityQueue
G={
    's':{'t':10,'y':5},
    't':{'x':1,'y':3},
    'x':{'z':4},
    'y':{'t':3,'z':2,'x':9},
    'z':{'x':6,'s':7}
}


def INITIALIZE_SINGLE_SOURCE(G, t):
    cost=dict()
    prev=dict()
    for vertex in G.keys():
        cost[vertex]=math.inf#infinity( 8 rotate(90 degree))
        prev[vertex]=" "
    cost[t]=0
    return cost,prev

def RELAX(G,u,v,cost,prev):
    if cost[v]>cost[u]+G[u][v]:
        cost[v]=cost[u]+G[u][v]
        prev[0]=u
    return cost,prev
def DJ(G,t):
    cost,prev=INITIALIZE_SINGLE_SOURCE(G,t)
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

def RECONSTRUCT_PATH(vertex,prev):
    path=vertex
    while prev[vertex]!=" ":
        path=path[vertex]+'->'+path
        vertex=prev[vertex]
    return path
t='t'
cost,prev=DJ(G,t)
for vertex in G.keys():
    print(f'Shortest Path From {t} to {vertex} is {RECONSTRUCT_PATH(vertex,prev)}')
    print(f'Cost is {cost[vertex]}')


