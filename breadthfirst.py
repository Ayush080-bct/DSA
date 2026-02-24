from queue import Queue

visited = []
q = Queue()

G = {
    'A': {'B', 'C'},
    'B': {'A', 'C'},
    'C': {'A', 'B', 'D'},
    'D': {'C', 'E', 'F'},
    'E': {'D', 'F'},
    'F': {'D', 'E'}
}

start_vertex = 'A'
q.put(start_vertex)

while not q.empty():
    vertex = q.get()
    if vertex not in visited:
        visited.append(vertex)
        # Add all neighbors to the queue
        for neighbor in G[vertex]:
            if neighbor not in visited:
                q.put(neighbor)

print("BFS Traversal:", visited)
