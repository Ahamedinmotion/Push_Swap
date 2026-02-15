*This project has been created as part of the 42 curriculum by <sshameer>.*

---

# push_swap

## 📌 Description

**push_swap** is a sorting algorithm project from the 42 curriculum that challenges students to sort a list of integers using a restricted set of stack operations while minimizing the number of moves.

The project focuses on:

* Algorithm design
* Time complexity optimization
* Data structure implementation
* Instruction cost analysis

The program receives a sequence of integers as arguments and outputs the **smallest possible list of operations** required to sort them in ascending order.

Two stacks are used:

* **Stack A** → Contains the initial unsorted numbers
* **Stack B** → Auxiliary stack used for sorting

The challenge lies not in sorting itself, but in doing so **efficiently under strict operational constraints**.

---

## ⚙️ Allowed Operations

Sorting must be performed using only the following instructions:

### Swap

* `sa` → Swap first 2 elements of stack A
* `sb` → Swap first 2 elements of stack B
* `ss` → Execute `sa` and `sb`

### Push

* `pa` → Push top of B to A
* `pb` → Push top of A to B

### Rotate

* `ra` → Shift up all elements of A
* `rb` → Shift up all elements of B
* `rr` → Execute `ra` and `rb`

### Reverse Rotate

* `rra` → Shift down all elements of A
* `rrb` → Shift down all elements of B
* `rrr` → Execute `rra` and `rrb`

---

## 🧠 Implemented Sorting Strategies

This implementation uses an **adaptive sorting approach** based on input size and disorder level.

### 1️⃣ Small Sort (≤ 5 numbers)

Hardcoded optimal sequences designed to achieve the minimum possible move count.

---

### 2️⃣ Selection Sort (Conceptual Base)

Used as a conceptual foundation to understand minimal extraction logic under constrained operations.

---

### 3️⃣ Chunk Sort (Primary Algorithm ≤ 500)

Numbers are divided into chunks based on indexed ranking, then pushed and reassembled efficiently to reduce total operations.

---

### 4️⃣ Indexed Sorting

All values are indexed relative to their sorted order to simplify comparisons and enable chunk-based logic.

> Radix sort was intentionally omitted since this implementation targets optimal performance under 500 numbers.

---

## 🎯 Project Goals

* Sort **100 numbers** in **< 700 operations**
* Sort **500 numbers** in **< 5500 operations**

✅ **Targets achieved**

---

## 🚀 Compilation & Usage

### Compilation

```bash
make
```

This generates:

```bash
./push_swap
```

---

### Usage

```bash
./push_swap <list_of_integers>
```

#### Example

```bash
./push_swap 3 2 1
```

**Output**

```
sa
rra
```

---

## 🧪 Testing With Checker

If you have the checker program:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
```

**Output**

```
OK
```

---

## 📊 Performance Testing

Generate random numbers:

```bash
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

This outputs the total number of operations used.

---

## ❗ Error Handling

The program handles:

* Non-integer inputs
* Integer overflow
* Duplicate numbers
* Empty arguments
* Invalid formatting

On error, the program outputs:

```
Error
```

---

## 🛠️ Technical Choices

### Data Structure

* Linked list stacks
* Dynamic memory allocation

---

### Why Linked Lists?

* Efficient rotations
* Constant-time pushes/pops
* Flexible memory handling

---

### Indexing Instead of Raw Values

Indexing normalizes data, enabling:

* Faster comparisons
* Chunk partitioning
* Bitwise/radix compatibility
* Reduced instruction cost

---

## ⏱️ Time Complexity Considerations

While push_swap evaluates **operation count**, algorithmic complexity still influences performance.

| Algorithm        | Complexity  | Usage             |
| ---------------- | ----------- | ----------------- |
| Small Sort       | O(1)        | ≤ 5 elements      |
| Selection Logic  | O(n²)       | Conceptual base   |
| Chunk Sort       | ~O(n log n) | Primary algorithm |
| Radix (optional) | O(n log n)  | Large datasets    |

Optimization focuses on **reducing instruction count**, not CPU execution time.

---

## 📂 Project Structure

src/
│── main.c
│── parsing.c
│── indexing.c
│── operations.c
│── small_sort.c
│── chunk_sort.c
│── utils.c
│── push_swap.h
Makefile
README.md
```

---

## 📚 Resources

### Algorithms & Sorting

* Knuth — *The Art of Computer Programming*
* CLRS — *Introduction to Algorithms*
* VisuAlgo Sorting Visualizer
* GeeksForGeeks — Sorting Algorithms
* Big-O Cheat Sheet

---

### push_swap References

* 42 Intra Subject PDF
* Community push_swap visualizers
* Operation optimizers on GitHub

---

## 🤖 AI Usage Disclosure

AI tools (ChatGPT) were used in the following capacities:

* Conceptual explanations of sorting algorithms
* Time complexity breakdowns
* Debugging guidance
* Architectural planning
* README structuring

All code logic, implementation decisions, optimizations, and testing were performed and validated manually in compliance with **42 academic integrity policies**.

---

## 👤 Author

**Login:** <sshameer>
**School:** 42 Abu Dhabi
**Project:** push_swap
**Year:** 2026

---
