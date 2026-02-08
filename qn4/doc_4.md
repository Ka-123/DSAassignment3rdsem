# My QN 4 Report (Doubly Linked List)

## The Struct (The Box)
So first I made a struct called `d_node`. It has three parts inside:
- `value`: This is for holding the actual number.
- `next_guy`: A pointer that points to the next node in the line.
- `prev_guy`: Another pointer that points back to the previous node.
This is why it's called "doubly" because you can go both ways, left or right!

## What my functions do
1. **`put_after`**: This function takes a node and a new number. It creates a new node (`fresh_node`) and tries to squeeze it in right after the `target` node. You have to fix four pointers basically so the whole chain doesn't break.
2. **`kill_node`**: This one is for removing a node. You just have to tell the neighbors of the node being deleted to look at each other instead. Like, the previous guy should now point to the next guy, and the next guy should point back to the previous guy.
3. **`print_all`**: Simple function to print the list so I can double check if my logic is right.

## How Main works
In the `main()` part:
- I created the first node (`head_ptr`) with 100.
- Then I put 200 after 100.
- Then I put 300 after 200.
- After that, I deleted 200 to see if 100 and 300 would connect correctly.
- It works! 100 now points straight to 300.

## Sample Run Result
This is what showed up on my screen:
```
Initial list: 100 <-> NULL
Adding 200 after 100...
100 <-> 200 <-> NULL
Adding 300 after 200...
100 <-> 200 <-> 300 <-> NULL
Deleting 200 now...
100 <-> 300 <-> NULL
```
The logic is solid and the code is easy to read!
