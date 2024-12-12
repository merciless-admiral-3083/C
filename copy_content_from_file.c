#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourceFilename[100], targetFilename[100];
    char ch;
    int charCount = 0;

    // Get the source and target file names from the user
    printf("Enter the source file name: ");
    scanf("%s", sourceFilename);
    printf("Enter the target file name: ");
    scanf("%s", targetFilename);

    // Open the source file in read mode
    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Cannot open source file.\n");
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen(targetFilename, "w");
    if (targetFile == NULL) {
        printf("Cannot open target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source file to target file and count characters
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
        charCount++;
    }

    // Close both files
    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");
    printf("Total number of characters: %d\n", charCount);

    return 0;
}
