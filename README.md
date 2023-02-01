# Push_Swap

School 42 Project that consists in sorting a given list of numbers in ascending order, in the least amount of operations.

Here, "the least amount of operations" aims to fit the requirements to have the maximum score for the project.

Under    3 operations for   3 numbers

Under   12 operations for   5 numbers

Under  700 operations for 100 numbers

Under 5500 operations for 500 numbers


Therefore, the algorithm can certainly be optimized further.


# Operations

The possible operations are the following :

| Operation | Meaning | Effect |
| :---------: | :----: | :------------- |
| sa  | Swap a | Swaps/echanges the first 2 nodes of stack A. Does nothing if there is only one node or no node |
| sb | Swap b | Swaps/echanges the first 2 nodes of stack B. Does nothing if there is only one node or no node |
| ss | Swap both | Does sa and sb at the same time |
| pa | Push a | Pushes the first node of stack B on top of stack A. Does nothing if stack B is empty. |
| pb | Push b | Pushes the first node of stack A on top of stack B. Does nothing if stack A is empty. |
| ra | Rotate a | Shifts up all nodes of stack A by 1. The fist node becomes the last node |
| rb | Rotate b | Shifts up all nodes of stack B by 1. The fist node becomes the last node |
| rr | Rotate both | Does ra and rb at the same time |
| rra | Reverse Rotate a | Shifts down all nodes of stack A by 1. The last node becomes the first node |
| rrb | Reverse Rotate b | Shifts down all nodes of stack B by 1. The last node becomes the first node |
| rrr | Reverse Rotate both | Does rra and rrb at the same time |


# Sorting Algorithm

## Tiny stacks (size = 3)
To obtain a sorted list of numbers with the least amount of operations, the following logic was used for **tiny** stacks :
  1. Check if the stack is aready sorted, in which case, no operations are needed
  2. Find the highest number and check its position in the stack
  3. Rotate / rev_rotate in order to have highest at the bottom of the stack
  4. Swap the other 2 numbers if they're not already in the right position

## Small stacks (size <= 5)
To obtain a sorted list of numbers with the least amount of operations, the following logic was used for **small** stacks :
  1. Check if the stack is aready sorted, in which case, no operations are needed
  2. Push the smallest numbers into stack B, keeping only 3 numbers in stack A
  3. Use **tiny sort** to sort stack A
  4. Push the numbers from stack B into stack A. As they are the smallest, they conveniently already be on top of       stack A.

## Big stacks (size > 5)
To obtain a sorted list of numbers with the least amount of operations, the following logic was used for **big** stacks :
  1. Check if the stack is aready sorted, in which case, no operations are needed
  2. Find the LIS (Longest Increasing Subsequence) of stack A, which is the longest existing list of numbers that      are already sorted and so, therefore, do not need to be pushed or sorted
    - See documentations : [LIS](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)  [Construction of LIS](https://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/?ref=gcse)
    
    Flag the numbers that are in the LIS so that they are recognizable from the non-LIs numbers
  3. Push all numbers from stack A into stack B (except the LIS flagged numbers) in chunks. The lowest numbers          will be at the bottom of stack B and as we go up the stack, the numbers get bigger
  4. Determine the cost to get each number on top of its stack
  5. Find the cheapest cost to get the number of stack B directly in the right position of stack A. Rotate or           rev_rotate to get those numbers on top of their respective stacks and push the number from stack B to stack       A. Repeat until stack B is empty
  6. Rotate or rev_rotate stack A until lowest number is at the top
