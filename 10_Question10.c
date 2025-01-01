//Q- WAP to take and display 10 students records as roll no. , name and mark using structure of array

//Header files declarations
#include <stdio.h>
#include <string.h>

//Structure to store students different details.
struct Details {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    int i, len;
    //We have to store the same type of information of 10 students. So structure array of 10 is made.
    struct Details students[10];

    //Take as input the details of the students one by one from the user via loop.
    for(i = 0; i < 10; i++) {
        printf("Enter details for student %d:\n", i + 1);   //(i+1) is To make the student count start from 1.
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);     //Takes roll number of the 10 students (0-9)
        getchar();  //when we click enter after typing roll number, fgets takes it as '\n' character. getchar() is used to overcome this.

        printf("Name: ");
        fgets(students[i].name, 50, stdin);  //fgets is used to read the full name including spaces. Stdin means we are taking input from the keyboard.

       /* When we press enter  for next line after putting one roll number, the compiler takes it as a character(\n).
            To overcome this, strcspn is used which finds the index of '\n'. So that we can change '\n' with null character (\0) to terminate the strings.*/
        len = strcspn(students[i].name, "\n");       //The index of new line character \n is stored in len.
       students[i].name[len] = '\0';      // Replace newline character with null character.

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n"); 
    }

    // Display the records of all 10 students using loop
    for(i = 0; i < 10; i++) {
        printf("Details of Student %d: \n", i+1);
        
        printf("%d. %s - %.2f marks\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    return 0;
}
