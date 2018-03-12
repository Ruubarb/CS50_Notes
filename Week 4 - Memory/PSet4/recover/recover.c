#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *memcard = fopen(infile, "r");
    if (memcard == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    uint8_t buffer[512]; //creates 512-byte sized block for buffer

    int headerCheck; //detects header block
    int jpegCheck; //detects non-header jpeg block

    int value = -1; //sprintf variable set to -1 since first filename must start with 0

    FILE *img = NULL;
    char filename[8]; //7 characters for filename and 8th for sentinel character



    while (fread(buffer, 1, 512, memcard) == 512) //loop ends if a block != 512, signaling the end-of-file (EOF)
    {
        //first four blocks of header must contain this data
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            headerCheck = 1; //header block found
            value++;

            if (jpegCheck == 1)
            {
                fclose(img);
                jpegCheck = 0;
                sprintf(filename, "%03i.jpg", value);
                img = fopen(filename, "w");
            }

            else
            {
                sprintf(filename, "%03i.jpg", value);
                img = fopen(filename, "w");
            }

        }

        if (headerCheck == 1)
        {
            jpegCheck = 1; //non-header jpeg block found
            fwrite(buffer, 1, 512, img);
        }
    }

    fclose(img); //final image closes when EOF is reached, meaning block less than 512 detected

    fclose(memcard);

    return 0;
}