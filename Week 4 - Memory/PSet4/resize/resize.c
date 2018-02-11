/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    if (n < 1 || n > 100)
    {
        printf("Please enter a value between 1 and 100\n");
    }

    //variables for headers changed by n, the outfile
    BITMAPFILEHEADER nf = bf;
    BITMAPINFOHEADER ni = bi;

    //only affects outfile
    ni.biWidth = bi.biWidth * n;
    ni.biHeight = bi.biHeight * n;
    int newPadding = (4 - (ni.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    ni.biSizeImage = ((sizeof(RGBTRIPLE) * ni.biWidth) + newPadding) * abs(ni.biHeight);
    nf.bfSize = ni.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&nf, sizeof(BITMAPFILEHEADER), 1, outptr); //writes to variable created above

    // write outfile's BITMAPINFOHEADER
    fwrite(&ni, sizeof(BITMAPINFOHEADER), 1, outptr); //writes to variable created above

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            /*
            //horizontal resize only
            for (int l = 0; l < n; l++)
            {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
            */
            for (int m = 0; m < n-1; m++)
            {
                //every row except for last row
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
        }

        // then add it back (to demonstrate how)
        for (int k = 0; k < newPadding; k++)
        {
            fputc(0x00, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);


    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
