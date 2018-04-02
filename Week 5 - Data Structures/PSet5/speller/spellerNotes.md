# Problem Notes

## Included Files Explanation

### dictionary.h and dictionary.c

1. **ifndef** and **define** checks if DICTIONARY_H has been defined earlier in the existing file or another file, if not previously defined it defines it.
2. **define LENGTH 45**Defines the max length for a word, 45 characters
3. **bool check(const char *word)** checks if the word is in the dictionary, and returns true if the word exist, false if not. The const keyword means this variable is immutable 
4. **bool load(const char *dictionary)** loads the dictionary. If the dictionary loads return true, if not return false.
5. **unsigned int size(void)** returns the number of words in the dictionary, but returns 0 if the dictionary isn't yet loaded.
6. **bool unload(void)** unloads the dictionary: true if successful, false if not.
7. **endif** ends the ifndef condition above

* Are *ifndef* and *indef* the start and end of an if statement?
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

* Main first checks if the correct number of arguments is entered
* rusage structs for before and after, the timing, are created
* benchmarks are done for the functions in dictionary.c and dictionary.h
* The program determines whether to use a dictionary from the argument, or the default dictionary
* The dictionary is loaded
* If the dictionary isn't loaded, abort the program
* time_load runs a benchmark to see how long it takes for the dictionary to load
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
* Error check is ran on the text file
* File is closed
* The dictionary's size is determined and a benchmark is ran on it
* Dictionary is unloaded, and if it can't be unloaded an error is printed 
* Benchmark on the dictionary's unload time is calculated
* Another benchmark is ran

---

###### texts

Speller looks for misspelled words from amongst the files in the **texts** directory. This directory is in gitignore.