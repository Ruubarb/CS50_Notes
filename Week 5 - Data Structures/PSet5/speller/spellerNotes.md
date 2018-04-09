# Problem Notes

## Included Files Explanation

### dictionary.h and dictionary.c

1. **ifndef** and **define** checks if DICTIONARY_H has been defined earlier in the existing file or another file, if not previously defined it defines it.
2. **define LENGTH 45** Defines the max length for a word, 45 characters
3. **bool check(const char *word)** checks if the word is in the dictionary, and returns true if the word exists, false if not. The const keyword means this variable is immutable 
4. **bool load(const char *dictionary)** loads the dictionary from the dictionary file. If the dictionary loads, return true, if not return false.
5. **unsigned int size(void)** returns the number of words in the dictionary, but returns 0 if the dictionary isn't yet loaded.
6. **bool unload(void)** unloads the dictionary: true if successful, false if not. Used to free memory.
7. **endif** ends the ifndef condition above

* Numbers 3-6 are functions we create in **dictionary.c**, that are called in **dictionary.h**


### makefile

When compiling the program, the **makefile** is important because it decides how it compiles. The **make** command is all that's needed, but **make clean** can be run if we need to delete any core files.

There's a blank section for libraries, in case we need to add any, though the walkthrough says that most likely won't happen.

* In this makefile we're compiling with clang and passing the usual flags
* dictionary.h is the header file, the source files are speller.c and dictionary.c
* The created executable will be speller.exe
* Any changes made to the makefile or the headers(dictionary.h) means the program needs to be re-compiled
* The files deleted when running the **make clean** command are any .exe or .o files created

### speller.c

#### General Notes

* **getrusage** is used to benchmark the implementations of **check**, **load**, **size**, and **unload**
	- getrusage, along with rusage, is used to examine the resource usage of a process
* The benchmarks are *double* data types, with **time_** prefixed before them
* **check** goes word by word in each text file. The misspellings are reported along with some statistics.
* The *dictionary* argument is optional, but if it's not used *dictionaries/large* runs by default
* However, a dictionary can't be loaded by the **speller.c** until the load function works

#### Program Notes

##### General

* Main first checks if the correct number of arguments is entered
* rusage structs for before and after, the timing, are created
* Benchmarks are done for the functions in dictionary.c and dictionary.h

##### Dictionary Loading

* The program determines whether to use a dictionary from the argument, or the default dictionary
* The dictionary is loaded
* If the dictionary isn't loaded, abort the program
* time_load runs a benchmark to see how long it takes for the dictionary to load

##### Spellchecker

* Text file is opened and a check is done to make sure it's not NULL
* File is spell-checked, word by word
	- Done within a for loop, which stops when the EOF is reached
	- Only alphabetical characters and apostrophes are checked
	- If a string is too long to be a word, it's ignored, and a new word is prepared by bringing the index back to 0
	- Any words containing numbers are ignored and a new word is prepared
		+ When a string is too long or when it contains numbers, the string is still followed through until its end
	- If a complete word is found, the **words** counter increases by 1
	- The word is spell checked and printed. The misspelling counter also increases by 1
	- time_check benchmark updates
	
##### After spellchecker 

* Error check is ran on the text file
* File is closed
* The dictionary's size is determined and a benchmark is ran on it
* Dictionary is unloaded, and if it can't be unloaded an error is printed 
* Benchmark on the dictionary's unload time is calculated
* Another benchmark is ran

---

###### texts

Speller looks for misspelled words from amongst the files in the **texts** directory. This directory, along with the keys and dictionaries directory, are in my gitignore.

---

## In Depth Explanation

### Linked List and Nodes
This problem's main data structure is the linked list. Either the linked list will be accessed by a hash table or a trie, it's up to the programmer. And each linked list, as with all linked lists, will contain nodes. My [previous notes](https://github.com/00SaadChaudhry/CS50_Notes/blob/master/Week%205%20-%20Data%20Structures/inDepthNotes.md#singly-linked-lists) go into detail about linked lists. This section will be more general and show syntax.

**Creating a node**

	typedef struct node
	{
		int value;
		struct node* next
	}
	node;
	node* head = malloc(sizeof(node)); // points to first node
	
**Use a loop to go through a linked list**

	node* cursor = head;
	while (cursor != NULL)
	{
		// some code
		cursor = cursor->next // move to the next node
	}
	
The list elements need to be freed properly, to prevent memory leaks. There are multiple ways of doing this. One way is to free them from tail to head, free the node pointing to NULL (the last node) until all nodes are free. However, this takes longer since the list needs to be cycled through each time until the tail is reached.  

**Another way is to create a temp pointer**

	node* cursor = head;
	while (cursor != NULL)
	{
		node* temp = cursor;
		cursor = cursor->next;
		free(temp);
	}
	
This piece of code creates a temp pointer and temp always points to the first node, and updates each iteration. This prevents the head node from being freed by itself and cutting off the rest of the nodes (which will leave them in memory).

#### Inserting Nodes

* To insert at the end, have the tail node point to the new node, and have the new node point to NULL
* To insert in-between, a temp pointer is needed. New node points to temp, temp points to ahead node, and behind node points to new node.
* To insert at the beginning, a temp pointer is needed. Temp points to first node, new points to temp, and the head pointer points to the new node.


### Load()

The dictionary can be loaded using a hash table or a trie, each with their own advantages and disadvantages.

#### Hash Table
If a hash table is used, the words will be stored within the linked list nodes that are within the hash table. The hash table will essentially be an array of linked lists.

A hash table has two disadvantages:  
Fixed size, so there will be problems if too many words are hashed.  
Collision, when multiple values are hashed to the same node.


	typdef struct node 
	{
		char word[LENGTH + 1];
		struct node* next;
	}
	node;
	node* hashtable[HASHTABLE_SIZE];
		
If a hash table is used, it will iterate over every word, and each word will become a new node. That word/node will be hashed into the table.
	

#### Trie
If a trie is used, each letter will be stored in its own node starting from the root all the way to the bottom. Each node will contain an array of node* pointers, and each array element will point to another node.

Tries have a dynamic capacity, and collision isn't a problem, but more code can be involved.

	typedef struct node 
	{
		bool is_word;
		struct node* children[27];
	}
	node;
	node* root;
	
Using a **for loop**, each word will be iterated through the trie. Each element will be checked to see if the letter already exists. If it doesn't (NULL node), a new node is malloc'd. If the letter exists, the node has a value other than NULL, it moves onto the next node. If the end of the word is reached, **is_word** is set to true.

### Size()
This function is the least complicated. It's suggested to have a running counter, as a global variable, in load and have size return that value. If a size function that counts every word is run, the runtime will increase significantly. 

### Check()
Whether using a hash table or a trie, the check function needs to be case-insensitive

#### Hash Table
It will look for a word by searching within the array element, then within the linked list, until it finds the node containing the word: hastable[hash(word)]. The inputted word will be compared to the word in the node using a string compare method. If the end of the list is reached, a NULL value, the word isn't in the dictionary.

#### Trie
Using a for loop, each node will be searching from top-to-bottom, going letter through letter until the word is found or until a NULL value is hit

### Unload()
Unload is similar whether using a hash table or a trie, but for a trie it's best to do it from bottom to top so there aren't any stray nodes in memory.

---

###### Valgrind
A necessity in this program since malloc and free are going to be used.