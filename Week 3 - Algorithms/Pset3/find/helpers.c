/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    int start = 0;
    int end = (n - 1);

    while (n > 0)
    {
        int mid = (start + end) / 2;
        if (value == values[mid])
        {
            return true;
        }
        else if (value > values[mid])
        {
            start = mid + 1;
        }
        else if (value < values[mid])
        {
            end = mid - 1;
        }
    }

    return false;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int counter = 13; //counter value a non-zero number, to get loop running properly
    int swap; //temporary swap variable


    for (int i = 0; i < n; i++)
    {
        counter = 0; //set to 0 for start of loop

        for (int j = 0; j < n - 1; j++)
        {
            if (values[j] > values[j+1])
            {
                swap = values[j]; //temporarily assigns left-side index to variable
                values[j] = values[j+1]; //switches left-side index with right-side
                values[j+1] = swap; //assigns right-side index to temp variable

                counter++; //increments whenever a swap is made
            }
        }
        //indicates end of swapping, all elements are in order
        if (counter == 0)
        {
            break;
        }
    }
}
