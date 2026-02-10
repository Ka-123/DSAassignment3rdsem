# Shortest Path using Dijkstra's Algorithm

I finally got around to implementing Dijkstra's algorithm. It sounded really complicated with all the talk about "priority queues" and "greedy strategies," but I found a much simpler way to do it using just basic arrays and loops.

## Data Structure: The Weighted Adjacency Matrix

To store the graph, I used a 2D array called `graphMap`. Each cell `graphMap[u][v]` holds the **cost** (or weight) to go from node `u` to node `v`. 
*   If the value is `0`, it means there's no direct path between those nodes.
*   Otherwise, the number represents how much it "costs" to travel that edge.

I also used a large number `9999` (which I called `VERY_FAR`) to represent infinity, just so the math doesn't break when we haven't found a path yet.

## How it Works (Function Descriptions)

Instead of using a fancy data structure, I used two simple arrays:
1.  `shortDist`: This keeps track of the best distance we've found so far from our **starting point** to every other node.
2.  `done`: A boolean array to remember which nodes we've already completely finished checking.

### Finding the Best Node
I wrote a function `findNextNode` that just loops through all the nodes and picks the one with the smallest distance that isn't `done` yet. It's basically a simple search, which I think is way easier to understand than those complex queues.

### The Relaxation Part
The main logic is in the `myDijkstra` function. It picks the "closest" node, marks it as `done`, and then looks at all its neighbors. If it finds that going through the current node creates a shorter path to a neighbor than what we knew before, it updates the `shortDist` array. This is the "relaxation" step!

## Main Logic

In the `main()` function, I set up a sample graph with 6 nodes. I connected them with different weights and then called the `myDijkstra` function starting from `Node 0`. 

## Sample Output

When I run the program, it calculates the shortest way to get everywhere from the start:

```text
Shortest distances from starting point (Node 0):
Distance to Node 0 is: 0
Distance to Node 1 is: 3
Distance to Node 2 is: 2
Distance to Node 3 is: 8
Distance to Node 4 is: 10
Distance to Node 5 is: 13
```


