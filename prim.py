#to find the minimum spanning tree for a graph
import math


G={
   'A':{'C':9,'B':4},
   'B':{'A':4,'C':1,'D':2},
   'C':{'A':9,'B':1,'E':5,'D':3},
   'D':{'E':3,'C':3,'B':2,'F':7},
   'E':{'C':5,'F':8,'D':3},
   'F':{'E':8,'D':7}
   }



def Extract_Minimum(cost,visited):
   min_cost=math.inf
   min_vertex=None
   for vertex in cost:
      if vertex not in visited and cost[vertex]<min_cost:
         min_cost=cost[vertex]
         min_vertex=vertex
   return min_vertex

def prim(G,start_vertex):
   visited = []  
   cost = dict() 
   parent = dict()
   for vertex in (G.keys()):
      cost[vertex]=math.inf
      parent[vertex]=None
   cost[start_vertex] = 0 
   print(cost)
   print(parent)
   
   while len(visited)<len(G):
      u=Extract_Minimum(cost,visited)
      visited.append(u)
      for v in G[u]:
         if v not  in visited and G[u][v] < cost[v]:
            cost[v]=G[u][v]
            parent[v]=u

   print("Minimum Spanning Tree:")
   for vertex in G:
        if parent[vertex] is not None:
            print(f"{parent[vertex]} - {vertex} (weight: {G[parent[vertex]][vertex]})")


prim(G,'A')


        
        
        
