# Understanding Heap Logic

Building heaps was a bit confusing at first, but I finally figured out how to use a simple array to represent a whole binary tree structure! It's actually pretty cool how the indexes work out.

## How the Array Represents a Tree

Basically, we don't need any complex nodes or pointers. We can just use a normal array and treat it like a "Complete Binary Tree." 

The trick is in the index math:
*   If a node is at index `i`, its **Left Child** is at `2 * i + 1`.
*   Its **Right Child** is at `2 * i + 2`.
*   And its **Parent** is at `(i - 1) / 2`.

Since it's a "complete" tree, all levels are full except maybe the last one, and everything is pushed to the left. This makes it perfect for an array.

## The 'Heapify' Process

I wrote two main functions: `fixDownMax` and `fixDownMin`. These are the "maintenance" functions.

When we want to fix a heap property at a certain index, we:
1.  Look at the parent and its two children.
2.  In a **Max-Heap**, we find the biggest of the three. In a **Min-Heap**, we find the smallest.
3.  If a child is bigger (for Max) or smaller (for Min) than the parent, we **swap them**.
4.  Then we have to keep "fixing down" recursion-style at the new child index because moving that number might have broken the heap property further down.

## Main Logic

To build the heap from an unsorted array, starting from the very first element and going down is inefficient. The better way (which I used) is to start from the **bottom-up**.

We start at the last non-leaf node (which is at index `(n/2) - 1`) and call our fix function on every node as we go up to the root. By the time we hit the root (index 0), the whole thing is a valid heap!

## Sample Output

Here is what happened when I ran my program with a test array:

```text
Original Array: 45 12 89 7 34 66 10 5 20 

Building Max-Heap...
Max-Heap: 89 34 66 20 12 45 10 5 7 

Building Min-Heap...
Min-Heap: 5 7 10 12 34 66 89 45 20 
```

The Max-Heap has the biggest number (89) at the top, and the Min-Heap has the smallest (5) at the top. Everything follows the rules!
