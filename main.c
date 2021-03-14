#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_arguments(int argc, char *argv[]);
void handle_lenght_specified_case(const char *filePath, unsigned int lineLenght);
void handle_default_case(const char *filepath);
void print_line(char *begin, unsigned int size, unsigned int startingByteNumber);
char *read_entire_file(const char *filepath, int *size);
int is_char_ok(unsigned char c);

void handle_arguments(int argc, char *argv[])
{
    if (argc == 3)
    {
        if (isdigit(*argv[1]))
        {
            int IntFirst = *argv[1] - '0';
            int IntSecond = *(argv[1] + 1) - '0';

            unsigned int Arg = 0;
            if (isdigit(*((argv[1]) + 1)))
                Arg = IntFirst * 10 + IntSecond;
            else
                Arg = IntFirst;

            if (Arg != 0)
            {
                printf("\n");
                handle_lenght_specified_case(argv[2], Arg);
            }
            else
            {
                printf("Wrong argument (0 is not allowed)...");
            }
        }
        else
        {
            printf("\nWrong argument...\n\n$ dumpy [bytes per line] [file path]\n\nExample:\ndumpy a.png\ndumpy 8 ./pass.txt\n");
        }
    }
    else if (argc == 2)
    {
        printf("\n");
        handle_default_case(argv[1]);
    }
    else
    {
        printf("\n$ dumpy [bytes per line ([1-99] default 16)] [file path]\n\nExample:\ndumpy a.png\ndumpy 8 ./pass.txt\n");
        exit(1);
    }
}

void handle_lenght_specified_case(const char *filePath, unsigned int lineLenght)
{
    int Size = 0;
    char *FileContent = read_entire_file(filePath, &Size);

    int GeneralByteCount = 0;

    while (GeneralByteCount < Size)
    {
        int BytesPerLine = Size - GeneralByteCount;
        if (BytesPerLine > lineLenght)
            BytesPerLine = lineLenght;

        print_line(FileContent, BytesPerLine, GeneralByteCount);
        FileContent += BytesPerLine;
        GeneralByteCount += BytesPerLine;
    }
}

void handle_default_case(const char *filePath)
{
    int Size = 0;
    char *FileContent = read_entire_file(filePath, &Size);

    int GeneralByteCount = 0;

    while (GeneralByteCount < Size)
    {
        int BytesPerLine = Size - GeneralByteCount;
        if (BytesPerLine > 16)
            BytesPerLine = 16;

        print_line(FileContent, BytesPerLine, GeneralByteCount);
        FileContent += BytesPerLine;
        GeneralByteCount += BytesPerLine;
    }
}

void print_line(char *begin, unsigned int size, unsigned int startingByteNumber)
{
    printf("%05x ", startingByteNumber);
    for (int i = 0; i < size; ++i)
    {
        char CharToPrint = begin[i];
        if (CharToPrint < 0)
            printf(" %02X ", (unsigned char)CharToPrint);
        else
            printf(" %02X ", CharToPrint);
    }

    printf("|");
    for (int i = 0; i < size; ++i)
    {
        char CharToPrint = begin[i];
        if (is_char_ok((unsigned char)CharToPrint))
            printf("%c", CharToPrint);
        else
            printf(".");
    }
    printf("|");
    printf("\n");
}

char *read_entire_file(const char *filePath, int *size)
{
    char *Buffer;
    int Size = 0;
    FILE *File = fopen(filePath, "rb");

    if (File)
    {
        fseek(File, 0, SEEK_END);
        Size = ftell(File);
        rewind(File);
        Buffer = (char *)malloc(sizeof(char) * Size);
        fread(Buffer, sizeof(char), Size, File);
    }
    else
    {
        printf("File is not found: %s", filePath);
        exit(1);
    }
    *size = Size;
    return Buffer;
}

int is_char_ok(unsigned char c)
{
    if (c == 0x7F)
        return 0;

    if (c <= 0xFF && c >= 0x21)
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    handle_arguments(argc, argv);
    return 0;
}
