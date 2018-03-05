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

    uint8_t buffer[512];
    int headerCheck = 0;
    int jpegCheck = 0;


    while (fread(buffer, 1, 512, memcard) == 512) //loop ends if a block != 512, signaling the raw files end
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            headerCheck = 1;
            if (jpegCheck == 1)
            {
                printf("\n-J-");
            }
            else
            {
                printf("new");
            }
        }

        if (headerCheck == 1)
        {
            jpegCheck = 1;
            printf("PEG");
        }
    }

    fclose(memcard);

    return 0;
}