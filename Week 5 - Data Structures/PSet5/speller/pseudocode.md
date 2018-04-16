# Speller Pseudocode

## Load

### Steps

1. Create hash table made up of linked lists.
2. Hash words from dictionary to place them into nodes

### Pseudocode


## Size

### Steps

1. Create a global counter variable
2. The counter variable should increment by 1 in **Load()**
3. Return this global variable in **Size()** after Load() runs

### Pseudocode


## Check

### Steps

1. Hash word into table
2. String compare hashed word with node value

### Pseudocode
[hash function source](https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c)


## Unload

### Steps

1. **Unload()** runs within a nested loop
2. This loop frees nodes from the tail to the head, freeing only nodes pointing to null

### Pseudocode
