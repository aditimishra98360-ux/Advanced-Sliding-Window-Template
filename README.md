# Advanced Sliding Window Template (Aggregation Queue)

## Overview
This repository contains an advanced sliding window template implemented in C++.
It efficiently supports aggregation queries (such as minimum) over a dynamic
window using stack-based decomposition.

The implementation is suitable for competitive programming and algorithmic
problems requiring fast range or window queries.

---

## Key Concepts Used
- Sliding Window Technique
- Amortized O(1) Operations
- Stack-Based Decomposition
- Operator Overloading
- Custom Data Aggregation

---

## Data Structures

### Info Structure
The Info struct stores aggregated values and defines how two elements are
combined using operator overloading. This design allows easy extension to
different aggregation types such as:
- Minimum
- Maximum
- Sum
- GCD

### Aggregate Stack (AggStack)
A stack that maintains prefix aggregates for all elements, allowing constant-time
aggregation queries.

### Aggregate Queue (AggQueue)
A queue built using two aggregate stacks to support:
- Push (add element to window)
- Pop (remove element from window)
- Query (get aggregated result over the window)

All operations run in **amortized O(1)** time.

---

## Algorithm Explanation
- Incoming elements are pushed into the in stack.
- When removing elements, data is transferred to the out stack with aggregation
  values recomputed.
- The current window aggregation is obtained by combining the aggregates from
  both stacks.

This approach avoids recomputation and ensures high performance even for large
inputs.

---

## Complexity Analysis
- Push operation: O(1) amortized
- Pop operation: O(1) amortized
- Query operation: O(1)

---

## Usage
This template can be directly used or modified for problems involving:
- Sliding window minimum, maximum, or, xor etc.
- Range aggregation queries
- Streaming data processing
- Competitive programming contests

---

## Technologies Used
- C++
- Standard Template Library (STL)
- Object Oriented Programming

---

## Author
Aditi Mishra  
IIEST Shibpur
