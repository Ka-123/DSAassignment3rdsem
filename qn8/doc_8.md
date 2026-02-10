# Random Sorting and Performance Tracking

I worked on a program that generates a bunch of random numbers and sorts them using Bubble Sort. The interesting part was tracking how much "work" the computer actually does to get the list in order.

## Data Structure: Standard Array

I used a simple standard array called `myNumbers` to hold the data. Since the user decides how many numbers they want (`howMany`), the array size is set at runtime. 

To fill the array, I used the `rand()` function to get integers between 1 and 1000. It's a nice way to get a messy list to test the sorting logic.

## The Sorting Function

I wrote a function called `myBubbleSort`. Here’s how it works:
*   It uses two nested `for` loops (using `i` and `j`) to compare adjacent numbers.
*   **Comparisons:** Every single time the `if` statement checks whether one number is bigger than the next, I increment `compCount`.
*   **Swaps:** Every time that condition is true and the numbers actually switch places, I increment `swapCount`.

By the end, the program tells us exactly how many times it had to check and move things around.

## Main Logic

The `main()` function handles the setup:
1.  It asks the user for the number of elements.
2.  It populates the array with random values.
3.  It prints the "Original List" so you can see the mess.
4.  It asks the user to choose the sorting method (I only implemented Bubble Sort for now).
5.  After sorting, it prints the "Sorted List" and the performance counts.

## Sample Output

Here is what it looks like when I ask for 10 numbers:

```text
How many random numbers do you want? 10

Original List: 
452 123 890 70 341 662 105 52 201 556 

Choose sorting algorithm (1 for Bubble Sort): 1

Sorting completed!
Total Comparisons: 45
Total Swaps: 24

Sorted List: 
52 70 105 123 201 341 452 556 662 890 
```


