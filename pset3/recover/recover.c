#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recoger rawfile\n");
        return 1;
    }

    // check rawfile
    char *rawfile = argv[1];
    FILE *pfile = fopen(rawfile, "r");
    if (pfile == NULL)
    {
        fprintf(stderr, "could not open file %s\n", rawfile);
        return 1;
    }

    // alloc memory to read mem blocks
    unsigned char *buffer = malloc(512);
    int n = 0;
    FILE *img;

    while (fread(buffer, 512, 1, pfile))
    {
        // new jpg found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close prev image
            if (n > 0)
            {
                fclose(img);
            }

            // create new file
            char filename[7];
            sprintf(filename, "%03i.jpg", n);

            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(pfile);
                free(buffer);
                fprintf(stderr, "could no create image file %s", filename);
                return 1;
            }

            n++;
        }

        if (!n)
        {
            continue;
        }

        fwrite(buffer, 512, 1, img);
    }

    // free
    fclose(pfile);
    fclose(img);
    free(buffer);

    return 0;
}