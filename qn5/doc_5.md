# My Graph Report for QN 5

## How I made the Graph
I used a 2D array (a matrix) called `myMatrix` to save the connections. 
- If `myMatrix[i][j]` is 1, it means there is a link between node `i` and node `j`.
- If it's 0, it means they are not connected.
It's an undirected graph, so whenever I add a link from `u` to `v`, I also add it from `v` to `u`.

## The Traversal stuff

### 1. DFS (Depth First Search)
I named the function `do_dfs`. It uses recursion to go deep into the graph. 
It picks a node, marks it as `seenIt`, and then immediately jumps to its first unvisited neighbor. 
It keeps going until it hits a dead end, then it backtracks to find other paths. 

### 2. BFS (Breadth First Search)
I named this one `do_bfs`. This one uses a queue called `waitingList`. 
Instead of going deep, it goes wide. It visits all the immediate neighbors first, then their neighbors, and so on. 
It's like a wave spreading out from the starting node.

## How the Main works
In the `main()` function:
- I set `totalNodes` to 5.
- I cleaned the `myMatrix` first by setting everything to 0.
- I added some links between nodes (like 0 to 1, 1 to 3, etc.).
- Then I just called both functions starting from node 0 to show the results.

## What it printed
When I run the program, this is the output:
```
DFS traversal starting from 0: 0 1 3 4 2 
BFS traversal starting from 0: 0 1 2 3 4 
```
The DFS path is different from BFS because DFS likes to explore one path fully before starting another one, while BFS goes layer by layer!
