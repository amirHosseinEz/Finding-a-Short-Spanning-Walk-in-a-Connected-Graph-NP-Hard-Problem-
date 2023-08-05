# Graph_Theory
finding a short spanning walk throw a connected graph (NP-HARD problem)

# Approach
After using various algorithms and testing them on big data, I was able to provide an algorithm that returns a very good and short answer.  
Algorithms that I used in order and the result of each of them in a graph with 15000 vertices and 52000 edges:  
(Algorithm : length of the path found)
1- Simple DFS : more than 28000 
2- Optimized DFS  : more than 24000 
3- Simple BFS : more than 28000  
4- Using both DFS and BFS so that first we used DFS to go deep, and to return instead of following the route, we found the shortest path using BFS and we were coming back: more than 28000  

5- Using the greedy algorithm to order the vertices in such a way that we start from one vertex and go to the nearest unseen vertex using BFS and repeat this process : more than 20000  

6- Using method 5, but this time, based on the degree of each vertex, we go to the nearest vertex that has a smaller degree among the other nearest vertices : around 18000  

# Result
The best method is method 6  
Since there were about 2000 leaves in this graph and we had 14,000 vertices, so the shortest spannig walk will definitely not be less than 16,000
The value returned by Algorithm 6 is very close to this number wich is 18000  
