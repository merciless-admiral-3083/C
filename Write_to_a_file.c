#include <stdio.h>

int main() {
    FILE *file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "First line of text.\n");
    fprintf(file, "Second line of text.\n");
    fprintf(file, "Third line of text.\n");

    fclose(file);

    return 0;
}