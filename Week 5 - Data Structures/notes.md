# CS50 Week 5 - Data Structures


## Nodes and Linked Lists

### Nodes
A piece in data structure, can have any name assigned to it, but is referred to as a **node**. It recursively refers to itself.

Nodes contain the value and a pointer to next node.
	
### Linked Lists
A collection of nodes linked together with pointers.

A linked list needs a **first** pointer to start off with. It needs to be followed 1-by-1, you can't jump ahead to another node in a linked list. These nodes are chained together, with each node pointing to the next. The list ends when a node points to null.


#### INSERT, DELETE, SEARCH
Algorithms used in linked lists. 

* Insert, without sorting the list is O(1), but with sorting is O(n)
* Search is O(n)
* Delete is O(n)


## Data Stacks

Data can be stacked on top of each other and is Last In First Out (**LIFO**). 

## Queues
These use Enqueue and Dequeue, and is First In First Out (**FIFO**).

## Data Trees
This data structure starts with a root and branches into parents, children, siblings, and leaves.

* The root is the beginning of the tree, everything starts from here.  
* A parent has data branching off from it, known as children.  
* Multiple children from the same parent are known as siblings.  
* Data without children are known as leaves.

### Binary Search Tree
The root of this tree is the middle value, the left child contains smaller sized values and the right contains larger sized values.

There are only two children per parent, that way the parent root **always** contains the middle value, the left always contains smaller values, and right always containers larger values.

### Huffman Algorithm
A tree combining the smallest nodes into the root. The most used nodes have the most direct/shortest paths to access them.

This is also a kind of data compression.

### Hash Tables
Tables that contain arrays of data. There's a linked list within each array.

## Trie
A tree with nodes containing an array.