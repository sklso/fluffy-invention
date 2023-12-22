#include <stdio.h>
#include <string.h>

#define MAX_NUM 30
#define MAX_COURSE 6

typedef struct {
    int num;
    char name[20];
    int score[MAX_COURSE];
    int total_score;
    float average_score;
} Student;

void input_record(Student students[], int *num_students) {
    int id, score;
    char name[20];
    printf("Enter student ID: ");
    scanf("%d", &id);
    printf("Enter student name: %s", name);
    printf("Enter scores of each course (up to %d): ", MAX_COURSE);
    for (int i = 0; i < MAX_COURSE; i++) {
        scanf("%d", &score);
        students[id - 1].score[i] = score;
    }
    printf("Enter total score: ");
    scanf("%d", &students[id - 1].total_score);
    printf("Enter average score: ");
    scanf("%f", &students[id - 1].average_score);
    (*num_students)++;

}
void calculate_total_and_average_score(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        int total_score = 0;
        float average_score = 0;
        for (int j = 0; j < MAX_COURSE; j++) {
            total_score += students[i].score[j];
        }
        average_score = total_score / MAX_COURSE;
        students[i].total_score = total_score;
        students[i].average_score = average_score;
    }
}

void calculate_total_and_average_score_by_course(Student students[], int num_students) {
    int total_score = 0;
    float average_score = 0;
    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < MAX_COURSE; j++) {
            total_score += students[i].score[j];
        }
    }
    average_score = (float)total_score / num_students;

    printf("Total score of each course: ");
    for (int i = 0; i < MAX_COURSE; i++) {
        printf("%d ", total_score);
        total_score = 0;
    }
    printf("\nAverage score of each course: %.2f\n", average_score);
}

void calculate_student_rank(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].total_score -= 50; // Adjust for easier comparison
    }
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[i].total_score > students[j].total_score) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void calculate_student_rank_by_course(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].total_score -= 50; // Adjust for easier comparison
    }
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[i].total_score > students[j].total_score) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for (int i = 0; i < num_students; i++) {
        students[i].total_score += 50; // Adjust back to original scale
    }
}

void sort_by_number(Student students[], int num_students) {
    Student temp;
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void sort_by_name(Student students[], int num_students) {
    Student temp;
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void search_by_number(Student students[], int num_students) {
    int id, rank;
    char query[20];
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    printf("Student ID: %d, Rank: ", id);
    for (int i = 0; i < num_students; i++) {
        if (students[i].num == id) {
            rank = i + 1;
            strcpy(query, students[i].name);
            break;
        }
    }
    if (rank) {
        printf("Rank: %d, Name: %s\n", rank, query);
    } else {
        printf("Student not found.\n");
    }
}

void search_by_name(Student students[], int num_students) {
    char name[20], query[20];
    int rank;
    printf("Enter student name to search: ");
    scanf("%s", name);
    printf("Student Name: %s, Rank: ", name);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            rank = i + 1;
            strcpy(query, students[i].name);
            break;
        }
    }
    if (rank) {
        printf("Rank: %d, Name: %s\n", rank, query);
    } else {
        printf("Student not found.\n");
    }
}

void statistics(Student students[], int num_students) {
    int count[MAX_NUM];
    float percentage[MAX_NUM];
    int total_passing = 0;
    int total_failing = 0;

    memset(count, 0, sizeof(count));

    for (int i = 0; i < num_students; i++) {
        count[students[i].num]++;
        if (students[i].total_score >= 90) {
            total_passing++;
        } else {
            total_failing++;
        }
    }

    float percentage_passing = (float)total_passing / num_students * 100;
    float percentage_failing = (float)total_failing / num_students * 100;

    printf("Scores Breakdown:\n");
    for (int i = 1; i < MAX_NUM; i++) {
        printf("Student ID: %d, Number of Students: %d\n", i, count[i]);
    }
    printf("Passing Percentage: %.2f%%\n", percentage_passing);
    printf("Failing Percentage: %.2f%%\n", percentage_failing);
}

void list_record(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student ID: %d, Name: %s, Scores: ", students[i].num, students[i].name);
        for (int j = 0; j < MAX_COURSE; j++) {
            printf("%d ", students[i].score[j]);
        }
        printf(", Total Score: %d, Average Score: %.2f\n", students[i].total_score, students[i].average_score);
    }
}

void print_menu() {
    printf("1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in ascending order by total score of every student\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10. Statistic analysis\n");
    printf("11. List record\n");
    printf("0. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    Student students[MAX_NUM];
    int num_students = 0;

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_record(students, &num_students);
                break;
            case 2:
                calculate_total_and_average_score(students, num_students);
                break;
            case 3:
                calculate_total_and_average_score_by_course(students, num_students);
                break;
            case 4:
                calculate_student_rank(students, num_students);
                break;
            case 5:
                calculate_student_rank_by_course(students, num_students);
                break;
            case 6:
                sort_by_number(students, num_students);
                break;
            case 7:
                sort_by_name(students, num_students);
                break;
            case 8:
                search_by_number(students, num_students);
                break;
            case 9:
                search_by_name(students, num_students);
                break;
            case 10:
                statistics(students, num_students);
                break;
            case 11:
                list_record(students, num_students);
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