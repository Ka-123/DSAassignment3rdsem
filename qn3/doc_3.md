# My Report for QN 3 (Reverse List)

## The Node thing
So I made a struct called `Node`. It has an integer `val` to keep the number and a pointer called `nextnode` which points to the next guy in the list. Without the pointer it wouldn't be a linked list right?

## How I printed it backwards
I used recursion for this. The function is `print_backwards`. 
Basically it keeps calling itself for the next node until it hits the end (NULL). 
Once it reaches the end, it starts coming back and prints the numbers while returning. 
This makes it print from the last one to the first one. It's like magic because the computer remembers the order for me.

## The Main part
In the `main()` function:
1. I started with a NULL pointer for the list.
2. I added some numbers (10, 20, 30, 40, 50) using the `add_item` function.
3. Then I called `print_backwards` to show the result.

## What it looks like
When I run it, it shows this:
```
original list was: 10 20 30 40 50
printing it in reverse now: 50 40 30 20 10 
```
It works perfectly!
