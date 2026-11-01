# Campus Route Finder - C DSA Mini Project Report

## Graph Representation

The project represents the campus as an undirected, unweighted graph.
It uses an adjacency list as the main representation and also maintains an
adjacency matrix.

In the adjacency list, each campus location has a linked list containing all
directly connected locations. This saves memory when the graph is sparse.

In the adjacency matrix, `adjMatrix[i][j] = 1` means there is a direct route
between location `i` and location `j`.

## BFS Algorithm

Breadth-First Search uses a queue. It starts from the source location, visits
all directly connected locations first, and then moves to the next level.

Because the campus graph is unweighted, BFS finds the route with the minimum
number of edges. The program stores the parent of every visited location and
uses recursion to print the route from source to destination.

## DFS Algorithm

Depth-First Search uses recursion. It starts from a source location and moves
as deeply as possible along one route before backtracking.

DFS is used to:

- Display all reachable locations
- Check whether a destination is reachable
- Find connected components
- Identify disconnected locations

## Complexity Analysis

Let V be the number of campus locations and E be the number of routes.

| Operation | Adjacency List | Adjacency Matrix |
|---|---:|---:|
| Space complexity | O(V + E) | O(V^2) |
| BFS time complexity | O(V + E) | O(V^2) |
| DFS time complexity | O(V + E) | O(V^2) |
| BFS/DFS extra space | O(V) | O(V) |
| Edge lookup | O(degree) | O(1) |

With an adjacency list, BFS and DFS visit every vertex once and scan every
edge, giving O(V + E) time. With an adjacency matrix, each vertex requires
scanning V possible neighbours, giving O(V^2) traversal time. [2][3]

## Test Cases

### Test Case 1: Direct Route

Input: Main Gate to Parking  
Expected: A route with 1 edge  
Actual: Main Gate -> Parking  

### Test Case 2: Multi-Stop Route

Input: Main Gate to Lab  
Expected: Minimum-edge route  
Actual: Main Gate -> Block 1 -> Block 2 -> Cafeteria -> Auditorium -> Lab  

### Test Case 3: Unreachable Destination

Input: Main Gate to Sports Ground  
Expected: No route  
Actual: No route found between Main Gate and Sports Ground.  

## Conclusion

The C program successfully demonstrates graph representation, BFS, DFS,
path reconstruction, reachability, and connected-component detection. BFS is
appropriate for shortest paths in an unweighted graph, while DFS is useful for
reachability and component analysis. [12][16]
