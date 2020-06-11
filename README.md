# Knapsack problem

The knapsack problem is a problem in combinatorial optimization: Given a set of items, each with a
weight and a value, determine the number of each item to include in a collection so that the total
weight is less than or equal to a given limit and the total value is as large as possible

## Method used

To solve this problem i used **DP -> Dynamic Programming**, witch is a method for solving
optimization problems. The idea is to compute the solutions to the subsub-problems *once* and
store the solution in a table, so that they can be *reused* later.

### Developing the **DP**

  1. Decompose the problem into smaller problems.
  2. Recursively define the value of an optimal solution in terms of solutions to smaller problems.
  3. Bottom-up computing using iteration

## Final Notes

With this project i learned what is a **DP** and how use this method, the method used in this
project has a time complexity of **O(n\*W)** where *n* is the array size and *W* is the knapsack
space, this also means that the space complexity is the same as it needs to use a 2D array.

## References

[Lecture 13: The knapsack Problem](http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf)<br>
[Lecture 8: Dynamic Programing](http://www.cse.unl.edu/~goddard/Courses/CSCE310J/Lectures/Lecture8-DynamicProgramming.pdf)<br>
[0-1 Knapsack problem](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)<br>
