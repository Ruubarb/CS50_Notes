# In Depth Notes on Data Structures

---

### Arrays and Linked Lists
Both arrays and linked lists are collection of the same data type. They have their advantages and disadvantages.

With arrays, you can search for an element in the array without going through the entire array by simply looking for a particular index number. However, arrays have a fixed capacity, meaning if your array has a length of 100, adding 101 items or more causes problems.

With linked lists, the capacity is dynamic, it can expand and shrink as needed. However, a [linear search](https://github.com/00SaadChaudhry/CS50_Notes/blob/master/Week%203%20-%20Algorithms/notes.md#linear-search) needs to be done through the list to find one item, you can't just tell the program to specifically find an item.

Arrays and Linked Lists are used in the various data structures discussed here. Values can be added/removed using an array or a linked list. And in the case of Hash Tables, an array containing linked list elements is used.

---

## Singly Linked Lists
They're made up of nodes with a type and a pointer assigned to them. They're also a self-referential structure. This means that the name of the linked list can't match the name being referenced for it to work properly.

Linked Lists are made up of a chain of nodes, and each node contains the value and a pointer. The beginning of the list, commonly referred to as the **head** points to the first node, and the pointer in that node points to the value in the second node. The pointer in the second node points to the value in the third node...and so on.

These data structures are capable of **CREATE**, **SEARCH**, **INSERT**, AND **DELETE** functions.

* **CREATE** 
	- Allocates memory for the list. 
	- Initializes value field, a null pointer, and a return pointer to a new node
* **SEARCH** 
	- Tracks the first element of the list, searching through the node chain looking for the value
	- Before it does any of this, it creates a duplicate of the head node instead of moving that node around and causing issues
	- Is a linear search, so sorting is necessary
	- The search ends when the pointer points to *NULL*, meaning the value wasn't found
* **INSERT**
	- It tracks the head node and the value to be added as arguments
	- The value is added at the beginning, since order doesn't matter and adding it is instant, this also means the runtime is O(1)
	- The inserted value must point to the old head first, then the beginning of the list can start at the new value
		+	Not doing it the above way will orphan the rest of the list
* **DELETE**
	- An entire list or individual nodes can be deleted, but it's not recommended to delete nodes with a Singly Linked List
	- To delete an entire list move down the list until the end pointer, which points to NULL is reached
	- This list deletion works in a recursive manner, so if the pointer points to NULL, it gets deleted
	- That means the next node will now point to NULL, and so on until all nodes are deleted	

Singly Linked Lists that can only move forward. Meaning that once you move to a new node in a linked list, it's difficult to go back without having extra pointers. It's actually so difficult to go back that it's recommended to use Doubly Linked Lists instead.



## Doubly Linked Lists

## Stacks

## Queues

## Hash Tables

## Tries