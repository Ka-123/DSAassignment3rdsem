# My Report for QN 2 (Infix to Postfix)

## What data structures i used
I used the `stack` thing from C++ library. Basically it helps to keep operators and numbers in order. 

1. **For conversion:** I used a stack named `s1` to hold characters like `+` or `*`. It helps to see who has more priority and also keeps track of brackets `(` because they are tricky.
2. **For the math part:** I used another stack called `s2`. This one stores numbers (integers). When it sees a sign like `*`, it takes out the top two guys, does the math, and puts the answer back in.

## My Functions

### 1. `checkboss(char c)`
This one is for priority. It just gives a number. Like `^` is 3 (very important), and `+` is just 1. If it's not an operator, it just says 0. I call it check boss because it checks who is the boss between operators.

### 2. `mkpostfix(string input_str)`
This makes the expression into postfix. It goes through the string `input_str` and uses the stack `s1` to move things around. The result is stored in a string called `final_p`.

### 3. `calculate_now(string post_str)`
This evaluates the `post_str`. It uses `s2` to calculate. It converts character numbers to real integers. I also added a check so it doesnt crash if there are letters or no numbers.

### 4. `main()`
The main part that runs everything. It asks for input into `user_input`, then gets postfix into `result_p` and calls `final_result` for the final value.

## How it works basically
First, it takes your string. Then it runs the conversion to move operators after the numbers. After that, it takes that new string and computes the final number by popping and pushing to the stack.

## Sample stuff that happened
If I type `1*2+4`:
1. It sees `1`, puts in `final_p`.
2. Sees `*`, puts in `s1`.
3. Sees `2`, puts in `final_p`.
4. Sees `+`, `*` comes out because it's more important than `+`.
5. Finally `final_p` becomes `12*4+`.
6. Then `calculate_now` takes `1` and `2`, multiplies them for `2`, then adds `4` to get `6`.

**Result:** 
enter expression: `1*2+4`
postfix: `12*4+`
result: `6`
