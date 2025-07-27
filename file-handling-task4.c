#include <stdio.h>
#include <string.h>


void runLengthEncode(char *input) {
    int i, count;
    int len = strlen(input);

    printf("Compressed Output: ");

    for (i = 0; i < len; i++) {

        count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", input[i], count);
    }

    printf("\n");
}

int main() {
    char input[100];

    printf("Enter a string to compress (e.g., aaabbbbcc): ");
    scanf("%s", input);

    runLengthEncode(input);

    return 0;
}