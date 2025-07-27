#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("File error!\n");
        return;
    }

    char current, next;
    int count;

    current = fgetc(in);
    while (current != EOF) {
        count = 1;
        while ((next = fgetc(in)) == current) {
            count++;
        }


        fputc(current, out);
        fprintf(out, "%d", count);

        current = next;
    }

    fclose(in);
    fclose(out);
    printf("Compression complete. Output written to: %s\n", outputFile);
}

void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("File error!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {

        char numStr[10];
        int i = 0;

        while (isdigit(ch = fgetc(in))) {
            numStr[i++] = ch;
        }
        numStr[i] = '\0';

        int count = atoi(numStr);

        for (int j = 0; j < count; j++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("Decompression complete. Output written to: %s\n", outputFile);
}

// Main menu
int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("=== Run-Length Encoding Tool ===\n");
    printf("1. Compress file\n");
    printf("2. Decompress file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    printf("Enter output file name: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
