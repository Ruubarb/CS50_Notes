# CS50 Week 5 - Data Structures


## Nodes and Linked Lists

### Nodes
A piece in data structure, can have any name assigned to it, but is referred to as a **node**. It recursively refers to itself.

	typedef struct node
	{
		struct node *next
	}
	
* Node *list points to the beginning value of a list. 
* The pointer itself points to the beginning pointer. 
* The next pointer points next to whatever the first pointer points to.
	
### Linked Lists
Lists threaded together using pointers. These are a collection of nodes linked together with pointers.

A linked list needs a **first** pointer to start off with. It needs to be followed 1-by-1, you can't jump ahead to another node in a linked list.


#### INSERT, DELETE, SEARCH
Algorithms used in linked lists. 

* Insert, without sorting the list is O(1), but with sorting is O(n)
* Search is O(n)
* Delete is O(n)


## Data Stacks

Data can be stacked on top of each other, but if this occurs it's Last In First Out (**LIFO**). Using Enqueue and Dequeue, this can become First In First Out (**FIFO**).

## Data Trees
This data structure starts with a root and branches into parents, children, siblings, and leaves.

* The root is the beginning of the tree, everything starts from here.  
* A parent has data branching off from it, known as children.  
* Multiple children from the same parent are known as siblings.  
* Data without children or siblings are known as leaves.

### Binary Search Tree
The root of this tree is the middle value, the left child contains smaller sized values and the right contains larger sized values.

There are only two children per parent, that way the parent root **always** contains the middle value, the left always contains smaller values, and right always containers larger values.

### Huffman Algorithm
A tree combining the smallest nodes into the root. The most used nodes have the most direct/shortest paths to access them.

This is also a kind of data compression.

### Hash Tables
Tables that contain boxes of data. There's a linked list within each box.

## Trie
A tree with node containing an array, O(1).