# Problem Notes

## Included Files Explanation

### dictionary.h

1. **ifndef** and **define** checks if DICTIONARY_H has been defined earlier in the existing file or another file, if not previously defined it defines it.
2. **define LENGTH 45**Defines the max length for a word, 45 characters
3. **bool check(const char *word)** checks if the word is in the dictionary, and returns true if the word exist, false if not. The const keyword means this variable is immutable 
4. **bool load(const char *dictionary)** loads the dictionary. If the dictionary loads return true, if not return false.
5. **unsigned int size(void)** returns the number of words in the dictionary, but returns 0 if the dictionary isn't yet loaded.
6. **bool unload(void)** unloads the dictionary: true if successful, false if not.
7. **endif** ends the ifndef condition above

* Are *ifndef* and *indef* the start and end of an if statement?

### dictionary.c

### makefile

### speller.c

---

###### texts

Speller looks for misspelled words from amongst the files in the **texts** directory. This directory is in gitignore.