# Week 8 Reflection — Heap and Priority Queue

Answer concisely after your implementation passes the tests.

1. **Representation.** How can a `std::vector` represent a complete binary tree without storing child pointers?
We use math formulas with the array indices instead of pointers. For any node at index i, on the left it is is 2*i + 1, on the rights it is 2*i + 2, and its parent is (i - 1) / 2.

2. **Invariant.** State the shape invariant and heap-order invariant separately. Why does satisfying the heap-order invariant not make the whole vector sorted?
Shape invariant:The tree has to be a complete binary tree.
Heap-order invariant: Every parent node has to be greater than or equal to its children.

It's not fully sorted because the heap only cares about parent-child relationships vertically. It doesn't guarantee any specific order horizontally between different branches or siblings.

3. **Complexity.** Explain why sift-up and sift-down inspect at most `Θ(log n)` tree levels. Also state the vector-reallocation qualification for an individual `push()`.
Sift-up and sift-down only travel along a single path from the bottom to the top or from bottom to the top Since a complete binary tree's height is Theta(log n), they only check that many levels.
For push(), it takes O(log n) time on average. But if the vector runs out of space and has to resize and copy everything over, that single push takes O(n) time though because it happens rarely, the amortized time is still O(log n).

4. **Heapify.** Why can bottom-up heap construction run in `Θ(n)` even though one sift-down can cost `O(log n)`?
Because most of the nodes are at the bottom of the tree near the leaves, where sift-down barely does any work. Only a few nodes near the top take the full O(log n) time. When you add it all up, it averages out to a linear time of Theta(n).

5. **Library comparison.** Give one reason to use `std::priority_queue` in production code and one reason implementing `BinaryHeap` is pedagogically useful.
Production code: std::priority_queue is part of the standard library, so it's already optimized and safe. 
Pedagogically: Writing BinaryHeap from scratch helps actually to understand how index math, memory, and heap algorithms work under the hood.