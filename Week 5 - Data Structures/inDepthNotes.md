# In Depth Notes on Data Structures

---

### Arrays and Linked Lists
Both arrays and linked lists are collections of the same data type. They have their advantages and disadvantages.

With arrays, you can search for a single element by simply looking for a particular index number. However, arrays have a fixed capacity, meaning if your array has a length of 100, adding 101 items or more causes problems.

With linked lists, the capacity is dynamic, it can expand and shrink as needed. However, a [linear search](https://github.com/00SaadChaudhry/CS50_Notes/blob/master/Week%203%20-%20Algorithms/notes.md#linear-search) needs to be done through the list to find one item, you can't just tell the program to specifically find an item.

Arrays and Linked Lists are used in the various data structures discussed here. Values can be added/removed using an array or a linked list. And in the case of Hash Tables, an array containing linked list elements is used.

---

## Singly Linked Lists
They're made up of nodes with a type and a pointer assigned to them. They're also a self-referential structure. This means that the name of the linked list can't match the name being referenced for it to work properly.

Linked Lists are made up of a chain of nodes, and each node contains the value and a pointer. The beginning of the list, commonly referred to as the **head** points to the first node, and the pointer in that node points to the value in the second node. The pointer in the second node points to the value in the third node...and so on.

These data structures are capable of **CREATE**, **SEARCH**, **INSERT**, AND **DELETE** functions.

* **CREATE** 
	- Allocates memory for the list
	- Initializes a value field, a null pointer, and a return pointer to a new node
* **SEARCH** 
	- Tracks the first element of the list, searching through the node chain looking for the value
	- Before it does any of this, it creates a duplicate of the head node instead of moving that node around and causing issues
	- Is a linear search, so sorting isn't required
	- The search ends when the pointer points to *NULL*, meaning the value wasn't found
* **INSERT**
	- It tracks the head node and the value to be added as arguments
	- The value is added at the beginning, since order doesn't matter and adding it is instant, this also means the runtime is O(constant)
	- The inserted value must point to the old head first, then the beginning of the list can start at the new value
		+ *Not doing it the above way will orphan the the list*
* **DELETE**
	- An entire list or individual nodes can be deleted, but it's not recommended to delete nodes with a Singly Linked List
	- To delete an entire list move down the list until the end pointer, which points to NULL is reached
	- This list deletion works in a recursive manner, so if the pointer points to NULL, it gets deleted
	- That means the next node will now point to NULL, and so on until all nodes are deleted	

Singly Linked Lists  can only move forward. Meaning that once you move to a new node in a linked list, it's difficult to go back without having extra pointers. It's actually so difficult to go back that it's recommended to use Doubly Linked Lists instead.



## Doubly Linked Lists
These are similar to Singly Linked Lists, except they can move forward and backward. That means a node can be deleted without issues. They're created in a similar manner to Singly Linked Lists, except they also have a *prev pointer, to move backwards.

* **INSERT**
	- The prev pointer of the old head points to the new head
	- The prev pointer of the new head points to NULL
* **DELETE**
	- Used mainly to delete nodes in the middle of the list, it's difficult to delete beginning and end nodes
	- The node before the deleted node *next points to the node after the deleted node
	- The node after the delete node *prev points to the node before the deleted node

## Stacks
Data is organized in a **LIFO**, Last In First Out, manner. Think of it like a physical stack, if the bottom is removed the rest of the stack collapses, so the top needs to be removed first.

**Push()** adds an element to the top of the stack and **Pop()** removes an element from the top.

**Array based**

* Push needs to accept the pointer to the stack to actually change the stack and it's value. The index must also update by 1.
* Pop works similar, except the index decrements in value. The value is returned instead of actually being deleted. However, it's index can be overwritten with a new value.

**Linked List based**

* Push needs a new node created and new pointers set up
* Pop goes to the second element, makes it to the head node, and has a second pointer keep track of the new head

Stacks are used to grab the most recently added element.

## Queues
Similar concept to Stacks, except they're **FIFO**, First In First Out, like a queue of people.

**Enqueue** adds an element to the end of the queue, and **Dequeue** removes an element from the beginning of the queue.

**Array based**

* Enqueue needs to accept a pointer and a value to the queue. The value is added to the queue's end, and the queue size increases by 1.
* Dequeue accepts a pointer, and changes the location of the front element by 1. The size is decreased by 1 and the deleted value is returned.

**Linked List based**

* Works similar to a Doubly Linked List
* Enqueue has pointers for the head and tail of the linked list. It needs to follow the same rules as inserting an element into a linked list.
* Dequeue works in a similar manner as pop()

## Hash Tables
They combine abilities of arrays and linked lists, but they're not good for sorting data. When you're using a hash table, you care about the runtime in finding an element and don't want to increase it by sorting the hash table. You let the function decide where the element should go in the table.

The **hash function** returns a positive integer, known as a **hash code**, and an array that can store data. The value is run through the function, stored somewhere in the array, and is represented by the hash code. 

Instead of creating a hash function it's better to find one online (*and cite your source as you would for any function you didn't create*) because of the rules needed for a good hash function. 

Sometimes hash tables can experience a collision, which is multiple values being given the same key. One way to get around this is by **Linear Probing**. This is incrementing the hash code by 1 to find a suitable location. However, if Linear Probing goes increments too much it can lead to clustering, too much side-by-side data, which can lead to a collision. 

Another way to prevent collisions is **Chaining**, by having each element of the array contain multiple values. This is done by having linked lists as the elements and storing the values in those lists. Now one chain can be searched instead of the entire hash table.

## Tries
Tries are a data tree type of structure. Each key is always unique, and each value is a boolean. Tries combine arrays, structs, and pointers. 

A trie starts with a central root, labeled with digits, and is a recursive struct. When a location for data is found, another node is built and so on until the date is stored and the pointer equals NULL.  

Data is stored in the last node created. When data is inserted, nodes are *opened* along the way. If other data passes through the same nodes again, they don't need to be cleared again. 

When searching through a trie, the search starts from the root and ends until a NULL is hit. The search follows the path of the already opened nodes. The entire path is traversed until the value is found or the node points to NULL.

Tries have an O(n/constant) runtime, but take up a lot of memory to build.