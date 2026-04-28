# DSA-C

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![DSA](https://img.shields.io/badge/Data_Structures-Algorithms-orange?style=for-the-badge)
![Graphs](https://img.shields.io/badge/Graphs-Dijkstra%20%7C%20Prim%20%7C%20Topo-green?style=for-the-badge)
![Trees](https://img.shields.io/badge/Trees-BST%20%7C%20Morris%20%7C%20LCA-blueviolet?style=for-the-badge)

> Data Structures and Algorithms implemented in C from linked lists to graph theory.

---

## What This Is

A structured DSA repository built across three tracks -> **college class implementations**, ->**expert session deep dives**, and ->**lab assignments**. Everything is written in C with manual memory management and pointer based data structures.

This isn't a LeetCode grind repo. The focus is on building each structure from first principles and understanding *why* it works before moving to the next one.

---

## Repository Structure

```
DSA-C/
├── clg_class/              # Core DSA — taught and self-implemented
│   ├── boot_camp/          # Advanced: BFS, Morris Traversal, LCA, Excalidraw diagrams
│   ├── linked-lists/       # Singly, doubly, circular, Floyd's cycle, array-based
│   ├── queue/              # Circular array queue + linked list queue
│   ├── sorting/            # Bubble, insertion, quicksort
│   ├── stack/              # Array-based stack + linked list stack
│   └── tree/               # Binary tree + BST
├── expert_session/         # Advanced graph algorithms from guided sessions
│   ├── assignment/         # Linked list operation assignments
│   └── map/                # Graphs: Dijkstra, Prim's MST, topological sort, DFS
└── lab_dsa/                # Practical lab programs — real-world problem contexts
```

---

## Topics Covered

### Linked Lists — `clg_class/linked-lists/`

The most thoroughly covered topic in the repo every variant implemented.

| File | What It Implements |
|------|--------------------|
| `singly_linked_list.c` | Basic node creation, insert, delete, traverse |
| `doubly_linked_list.c` | Bidirectional links, forward/backward traversal |
| `circular_linked_list.c` | Circular singly linked list |
| `circular_doubly_linked_list.c` | Full circular doubly linked list |
| `linked_list_using_array.c` | Simulating linked list with array + index pointers |
| `floyd_cycle_algorithm.c` | Floyd's cycle detection — slow/fast pointer technique |
| `dsa_boot_camp.c` | List intersection problem |
| `class.c` / `evening_class.c` | In class implementations and variations |

---

### Stack — `clg_class/stack/`

Both classic implementations side by side.

| File | Implementation |
|------|---------------|
| `stack_using_array.c` | Static array stack with push/pop/peek |
| `linked_list_stack.c` | Dynamic stack using linked list nodes |

---

### Queue — `clg_class/queue/`

| File | Implementation |
|------|---------------|
| `circular_array_queue.c` | Circular queue with front/rear wrap-around |
| `linked_list_queue.c` | Dynamic queue using linked list |

---

### Sorting — `clg_class/sorting/`

| File | Algorithm | Complexity |
|------|-----------|------------|
| `bubble_sort.c` | Bubble Sort | O(n²) |
| `insertion_sort.c` | Insertion Sort | O(n²) avg, O(n) best |
| `quick_sort.c` | Quicksort | O(n log n) avg |

---

### Trees — `clg_class/tree/` + `clg_class/boot_camp/`

| File | What It Implements |
|------|--------------------|
| `binary_tree.c` | BT creation, inorder/preorder/postorder traversal |
| `bst.c` | Binary Search Tree -insert, search, delete |
| `boot_camp/bfs.c` | Breadth-First Search with level order traversal |
| `boot_camp/moris_traversal.c` | Morris Traversal - inorder without recursion or stack (O(1) space) |
| `boot_camp/lowest_common_ancestor.c` | LCA of two nodes in a binary tree |

> Morris Traversal and LCA are interview-level tree problems. Excalidraw diagrams (`.excalidraw`) are included alongside the code for visual reference.

---

### Graphs — `expert_session/map/`

The most advanced section — weighted graph algorithms implemented from scratch.

| File | Algorithm |
|------|-----------|
| `undirected_graph.c` | Adjacency list representation of undirected graph |
| `weight.c` | Weighted graph implementation |
| `dikstra.c` | Dijkstra's Shortest Path — greedy, priority based |
| `prim.c` | Prim's Minimum Spanning Tree |
| `topological_sort.c` | Topological ordering of a DAG |
| `dfs_recursion.c` | DFS — recursive implementation |
| `dfs_stack.c` | DFS — explicit stack implementation |

---

### Lab Programs — `lab_dsa/`

Applied DSA in real world problem contexts.

| File | Problem |
|------|---------|
| `lab1_media_management_system.c` | Media library management using linked list |
| `online_book_store.c` | Book store inventory using DSA |
| `mohanapriya_online_book_store.c` | Variant implementation |

---

### Expert Session Assignments — `expert_session/assignment/`

Isolated function level assignments covering linked list operations: create, insert (at beginning/end/position), delete, display, search, and count.

---

## Key C Concepts Practiced

| Concept | Where |
|---------|-------|
| Pointer arithmetic & `struct` node design | All linked list files |
| Manual `malloc` / `free` | All dynamic structures |
| Recursive tree traversal | `binary_tree.c`, `bst.c` |
| O(1) space tree traversal | `moris_traversal.c` |
| Slow/fast pointer technique | `floyd_cycle_algorithm.c` |
| Greedy algorithm with adjacency matrix | `dikstra.c`, `prim.c` |
| DAG ordering | `topological_sort.c` |
| Circular buffer wrap-around logic | `circular_array_queue.c` |

---

## Why C?

Embedded firmware runs on C. Every `malloc` here maps directly to understanding heap usage on a microcontroller. Every pointer operation maps to how ESP-IDF and FreeRTOS manage memory internally. This repo exists because writing DSA in C makes the embedded work sharper.

---
