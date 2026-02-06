# Documentation for question 1

## Stack Data Structure
stack is a "Last-In, First-Out" (LIFO) data structure. We use it here to keep track of opening brackets. When we see an opening bracket like `(`, `[` or `{`, we push it onto the stack. When we see a closing bracket, we check if it matches the one on top of the stack. If it does, we take it off. If the stack is empty at the end, everything was balanced.

## Functions
- `bool isitgoood(string someletters)`: This is the main function that checks if the string is balanced. It takes a string called `someletters`, loops through every character, and uses a stack to match brackets. It returns `true` if it's all good and `false` if something's wrong.

## main() Function Logic
The `main()` function defines three test strings as requested by the assignment. It then calls `isitgoood()` for each string and prints whether it's balanced or not using `cout`.

## Sample Output
```
Expression: a+(b-c)*(d
It is not balanced

Expression: m+[a-b*(c+d*{m)]
It is not balanced

Expression: a+(b-c)
It is balanced
```
