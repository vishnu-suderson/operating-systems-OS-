#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[] = "Hello, File Management!";
    file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    if (fputs(data, file) == EOF) {
        perror("Error writing to file");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("File Content: %s", buffer);
    }
    if (feof(file) == 0) {
        perror("Error reading from file");
    }
    fclose(file);
    return 0;
}

