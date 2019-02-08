//  input file to open for reading and output file to open for writing

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // does not equal three
    if (argc != 3)
    {
        fprintf(stderr, "Usage: Copy input file output file\n");
        return 1;
    }

    // input file output file names
    char *inputfile = argv[1];
    char *outputfile = argv[2];

    // open input file
    FILE *inptr = fopen(inputfile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inputfile);
        return 2;
    }

    FILE *outptr = fopen(outputfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outputfile);
        return 3;
    }

    // read input file BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read input file BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //  check file for 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write output file BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write output file BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iteration over scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterateover pixels
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temp storage
            RGBTRIPLE triple;

            // read RGB triple from input file
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            if (triple.rgbtRed == 0xff && triple.rgbtBlue == 0xff && triple.rgbtGreen == 0xff)
            {
                triple.rgbtRed = 0x00;
                triple.rgbtGreen = 0x00;
                triple.rgbtBlue = 0x00;
            }

            // write RGB triple to ouput file
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip padding
        fseek(inptr, padding, SEEK_CUR);

        // return padding
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close input file
    fclose(inptr);

    // close output file
    fclose(outptr);

    return 0;
}
