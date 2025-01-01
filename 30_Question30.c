#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char fileName[100];
    char data[256];

    // Get the name of the file to open
    printf("Enter the name of the file to open: ");
    scanf("%s", fileName);
    getchar(); //To remove the \n character after entering the file name, as fgets is present it will read \n as a character and jump to next line without taking input.

    // Open the file in read and write mode ("r+") - it will show error if the file doesn't exist
    file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Error: File does not exist.\n");
    }
    else{
    // Input the data to insert into the file
    printf("Enter the data to insert into the file (press ENTER to finish):\n");
    
    fgets(data, sizeof(data), stdin);

    // Write the data to the file
    fprintf(file, "%s", data);

    printf("Data successfully inserted into the file.\n");
    }

    // Close the file
    fclose(file);

    return 0;
}
