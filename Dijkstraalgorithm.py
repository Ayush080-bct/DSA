import heapq

class EdgeNode:
    def __init__(self, target, weight):
        self.target = target        # Target VertexNode
        self.weight = weight
        self.next = None
        self.prev = None

class VertexNode:
    def __init__(self, name):
        self.name = name
        self.edge_head = None       # Head of doubly linked list of EdgeNodes
        self.next = None
        self.prev = None

    def add_edge(self, target_vertex, weight):
        new_edge = EdgeNode(target_vertex, weight)
        if not self.edge_head:
            self.edge_head = new_edge
        else:
            temp = self.edge_head
            while temp.next:
                temp = temp.next
            temp.next = new_edge
            new_edge.prev = temp
    def __hash__(self):
        return hash(self.name)

    def __eq__(self, other):
        return isinstance(other, VertexNode) and self.name == other.name
    def __lt__(self, other):  # 👈 THIS FIXES heapq COMPARISON ISSUE
        return self.name < other.name



def show_connections(vertex):
    print(f"Vertex {vertex.name} connects to:")
    temp = vertex.edge_head
    if not temp:
        print("  No connections")
    while temp:
        print(f"  -> {temp.target.name} (weight: {temp.weight})")
        temp = temp.next
    print()

def dijkstra(vertices, start_vertex):
    cost = {v: float('inf') for v in vertices}
    prev = {v: None for v in vertices}
    visited = set()

    cost[start_vertex] = 0
    heap = [(0, start_vertex)]  # (distance, vertex)

    while heap:
        current_cost, current_vertex = heapq.heappop(heap)

        if current_vertex in visited:
            continue

        visited.add(current_vertex)

        edge = current_vertex.edge_head
        while edge:
            neighbor = edge.target
            weight = edge.weight

            if neighbor not in visited:
                new_cost = current_cost + weight
                if new_cost < cost[neighbor]:
                    cost[neighbor] = new_cost
                    prev[neighbor] = current_vertex
                    heapq.heappush(heap, (new_cost, neighbor))
            edge = edge.next

    # Print result
    for v in vertices:
        path = []
        crawl = v
        while crawl:
            path.append(crawl.name)
            crawl = prev[crawl]
        path.reverse()
        path_str = ' -> '.join(path)
        print(f"Shortest path to {v.name}: {path_str} (Cost: {cost[v]})")

#main
#createvertice
A = VertexNode('A')
B = VertexNode('B')
C = VertexNode('C')
D = VertexNode('D')
E = VertexNode('E')

#Buildgraph
A.add_edge(B, 3)
A.add_edge(C, 1)
B.add_edge(C, 7)
B.add_edge(D, 5)

C.add_edge(D, 2)
D.add_edge(E, 1)
E.add_edge(B, 1 )


# Vertex list for reference
vertices = [A, B, C, D, E]

# Show connections
for v in vertices:
    show_connections(v)

# Run Dijkstra
print("=== Dijkstra's Algorithm from A ===")
dijkstra(vertices, A)
