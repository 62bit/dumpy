#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_arguments(int argc, char *argv[]);
char *read_entire_file(const char *filepath, int *size);
void handle_default_case(const char *filepath);

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
            int arg = *argv[2] - '0';
            printf("%i\n", arg);
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

    int LineByteCount = 0;

    for (int i = 0; i < Size; ++i)
    {
        printf(" %0x ", *FileContent, *FileContent);
        LineByteCount++;
        if (LineByteCount == 16)
        {
            printf("\n");
            LineByteCount = 0;
        }

        FileContent++;
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
