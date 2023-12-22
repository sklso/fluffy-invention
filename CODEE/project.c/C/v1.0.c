 #include <stdio.h>

#define MAX_SIZE 30

typedef struct {
    int studentId;
    int score;
} Student;

void addRecord(Student array[], int *numStudents);
void calculateTotalAverage(Student array[], int *numStudents, int *total, int *average);
void sortRecordsByScore(Student array[], int *numStudents);
void sortRecordsByStudentId(Student array[], int *numStudents);
void searchRankScore(Student array[], int *numStudents, int studentId, int *rank, int *score);
void countStudentsInCategory(Student array[], int *numStudents, int *countIn90to100, int *countIn80to89, int *countIn70to79, int *countIn60to69, int *countIn59orBelow);
void displayRecords(Student array[], int *numStudents, int total, int average);

int main() {
    int choice, numStudents;
    Student records[MAX_SIZE];

    do {
        printf("Menu:\n");
        printf("1. Input record\n");
        printf("2. Calculate total and average score of course\n");
        printf("3. Sort in descending order by score\n");
        printf("4. Sort in ascending order by student id\n");
        printf("5. Search by student id\n");
        printf("6. Statistic analysis\n");
        printf("7. List record\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numStudents = 1;
                addRecord(records, &numStudents);
                break;
            case 2:
                int total, average;
                calculateTotalAverage(records, numStudents, &total, &average);
                printf("Total Score: %d, Average Score: %.2f\n", total, average);
                break;
            case 3:
                sortRecordsByScore(records, numStudents);
                printf("Records sorted by score in descending order:\n");
                displayRecords(records, numStudents, total, average);
                break;
            case 4:
                sortRecordsByStudentId(records, numStudents);
                printf("Records sorted by student id in ascending order:\n");
                displayRecords(records, numStudents, total, average);
                break;
            case 5:
                int rank, score;
                scanf("%d", &numStudents);
                searchRankScore(records, numStudents, numStudents, &rank, &score);
                printf("Rank: %d, Score: %d\n", rank, score);
                break;
            case 6:
                int countIn90to100, countIn80to89, countIn70to79, countIn60to69, countIn59orBelow;
                countStudentsInCategory(records, numStudents, &countIn90to100, &countIn80to89, &countIn70to79, &countIn60to69, &countIn59orBelow);
                printf("Number of students in each category:\n");
                printf("90-100: %d\n", countIn90to100);
                printf("80-89: %d\n", countIn80to89);
                printf("70-79: %d\n", countIn70to79);
                printf("60-69: %d\n", countIn60to69);
                printf("0-59: %d\n", countIn59orBelow);
                break;
            case 7:
                printf("Student Id: %d, Score: %d\n", records[0].studentId, records[0].score);
                printf("Total Score: %d, Average Score: %.2f\n", total, average);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 0);

    return 0;
} 