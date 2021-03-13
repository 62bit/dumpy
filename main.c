#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_arguments(int argc, char *argv[]);
char *read_entire_file(const char *filepath, int *size);
void handle_default_case(const char *filepath);
int is_char_ok(char c);

int main(int argc, char *argv[])
{
    parse_arguments(argc, argv);
    return 0;
}

#define LINE_ARGUMENT "-l"

void parse_arguments(int argc, char *argv[])
{
    printf("Number of arguments : %i\n", argc);

    if (argc == 3) // case with line size
    {
        int Equal = strcmp(argv[1], LINE_ARGUMENT);

        if (Equal == 0 && isdigit(*argv[2]))
        {
            // TODO : make another function to handle this case
            int Arg = *argv[2] - '0';
            printf("%i\n", Arg);
        }
        else
        {
            printf("Wrong argument...");
        }
    }
    else if (argc == 2)
    {
        handle_default_case(argv[1]);
    }
    else
        printf("Wrong argument...");
}

void handle_default_case(const char *filepath)
{
    int Size = 0;
    char *FileContent = read_entire_file(filepath, &Size);
    if (FileContent == NULL)
    {
        printf("File is not found!");
        exit(1);
    }

    printf("FFS...\n");

    int GeneralByteCount = 0;

    while (GeneralByteCount < Size)
    {
        int BytesPerLine = Size - GeneralByteCount;
        if (BytesPerLine > 16)
            BytesPerLine = 16;

        // Print hex values
        for (int i = 0; i < BytesPerLine; ++i)
        {
            char CharToPrint = FileContent[GeneralByteCount];
            if (CharToPrint > 0xF)
                printf(" %x ", CharToPrint);
            else
                printf(" 0%x ", CharToPrint);

            GeneralByteCount++;
        }

        // Print ASCII values
        printf("|");
        for (int i = 0; i < BytesPerLine; ++i)
        {
            char CharToPrint = FileContent[GeneralByteCount - (BytesPerLine - i)];
            if (is_char_ok(CharToPrint))
                printf(" %c ", CharToPrint);
            else
                printf(" . ");
        }
        printf("|");
        printf("\n");
    }
}

char *read_entire_file(const char *filepath, int *size)
{
    char *Buffer;
    int Size = 0;
    FILE *File = fopen(filepath, "rb");

    if (File)
    {
        fseek(File, 0, SEEK_END);
        Size = ftell(File);
        rewind(File);
        Buffer = (char *)malloc(sizeof(char) * Size);
        fread(Buffer, sizeof(char), Size, File);
    }
    else
        return NULL;
    *size = Size;
    return Buffer;
}

int is_char_ok(char c)
{
    if (c <= 0x254 && c >= 0x41)
        return 1;
    return 0;
}
