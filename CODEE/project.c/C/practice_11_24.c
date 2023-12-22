#include <stdio.h>  
  
#define MAX_STUDENTS 100  
  
struct Student {  
    int id;  
    float math;  
    float english;  
    float computer;  
    float average;  
};  
  
struct Student students[MAX_STUDENTS];  
int num_students;  
  
void calculate_average(struct Student *students, int num_students) {  
    int i;  
    float total_math = 0, total_english = 0, total_computer = 0;  
    for (i = 0; i < num_students; i++) {  
        total_math += students[i].math;  
        total_english += students[i].english;  
        total_computer += students[i].computer;  
    }  
    float total_average = (total_math / num_students) + (total_english / num_students) + (total_computer / num_students);  
    printf("Average of all students: %.2f\n", total_average);  
}  
  
void calculate_average_for_subject(struct Student *students, int num_students, char *subject) {  
    int i;  
    float total = 0;  
    for (i = 0; i < num_students; i++) {  
        total += students[i].math + students[i].english + students[i].computer;  
    }  
    float average = total / (num_students * 3);  
    printf("%s average: %.2f\n", subject, average);  
}  
  
void print_student(struct Student *student) {  
    printf("Student ID: %d\n", student->id);  
    printf("Math: %.2f\n", student->math);  
    printf("English: %.2f\n", student->english);  
    printf("Computer: %.2f\n", student->computer);  
    printf("Average: %.2f\n", student->average);  
}  
  
void print_students(struct Student *students, int num_students) {  
    int i;  
    for (i = 0; i < num_students; i++) {  
        print_student(&students[i]);  
    }  
}  
  
int main() {  
    int i;  
    printf("Enter the number of students: ");  
    scanf("%d", &num_students);  
    for (i = 0; i < num_students; i++) {  
        printf("Enter student ID, math score, English score, and computer score: ");  
        scanf("%d %f %f %f", &students[i].id, &students[i].math, &students[i].english, &students[i].computer);  
        students[i].average = (students[i].math + students[i].english + students[i].computer) / 3;  
    }  
    calculate_average(students, num_students);  
    calculate_average_for_subject(students, num_students, "Math");  
    calculate_average_for_subject(students, num_students, "English");  
    calculate_average_for_subject(students, num_students, "Computer");  
    print_students(students, num_students);  
    return 0;  
}