# Finding a Short Spanning Walk in a Connected Graph (NP-Hard Problem)

This repository contains an implementation of algorithms designed to find a short spanning walk in a connected graph, a classic NP-hard problem. The project explores various algorithmic approaches and evaluates their performance on large datasets.

## Problem Overview

The task is to find a spanning walk that visits all vertices in a connected graph while minimizing the total path length. Given the NP-hard nature of this problem, we implemented several algorithms and tested them to determine their effectiveness.

## Approach

After extensive testing of various algorithms on a dataset consisting of a graph with **15,000 vertices** and **52,000 edges**, the following methods were applied:

### Algorithms Used

1. **Simple Depth-First Search (DFS)**  
   - **Result:** Path length greater than **28,000**  
   - **Description:** This algorithm explores as far as possible along each branch before backtracking, but does not guarantee an efficient path.

2. **Optimized Depth-First Search**  
   - **Result:** Path length greater than **24,000**  
   - **Description:** This variation of DFS incorporates heuristic optimizations to improve efficiency over the basic DFS.

3. **Simple Breadth-First Search (BFS)**  
   - **Result:** Path length greater than **28,000**  
   - **Description:** BFS explores all neighbors at the present depth prior to moving on to nodes at the next depth level, but also lacks efficiency in spanning all vertices.

4. **Combined DFS and BFS**  
   - **Result:** Path length greater than **28,000**  
   - **Description:** In this method, we use DFS to traverse deep into the graph initially. Given that the edges are unweighted, we utilize BFS to find the shortest path back instead of Dijkstra's algorithm, which is typically used for weighted graphs. However, this approach also results in an inefficient walk overall.

5. **Greedy Algorithm (Basic Version)**  
   - **Result:** Path length greater than **20,000**  
   - **Description:** This approach involves starting from a vertex and repeatedly moving to the nearest unseen vertex using BFS. This method improves efficiency but still does not yield the optimal solution.

6. **Degree-Based Greedy Algorithm**  
   - **Result:** Path length of approximately **18,000**  
   - **Description:** This method refines the greedy approach by prioritizing vertices based on their degree. It selects the nearest vertex with the smallest degree among the nearest unseen vertices, significantly improving the outcome.

## Results

The best performing method was the **Degree-Based Greedy Algorithm**, which produced a path length of approximately **18,000**. Given the presence of about **2,000 leaves** in the graph and **14,000 vertices**, the theoretical lower bound for the shortest spanning walk is no less than **16,000**. The result from this algorithm is very close to this theoretical lower bound, demonstrating its effectiveness.

## Conclusion

This project provides insights into various algorithmic strategies for solving the NP-hard problem of finding a short spanning walk in a connected graph. The Degree-Based Greedy Algorithm shows significant promise in terms of efficiency and effectiveness.


