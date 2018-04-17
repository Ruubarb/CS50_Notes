/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>

#include "dictionary.h"

#define NUM_BUCKETS 1000;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/*
Hash Function adapted by Neel Mehta from
http://stackoverflow.com/questions/2571683/djb2-hash-function.
*/
unsigned int hash_word(const char* word)
{
    unsigned long hash = 5381;

    for (const char* ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }

return hash % NUM_BUCKETS;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    unsigned int hash_word(const char* word);


    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
