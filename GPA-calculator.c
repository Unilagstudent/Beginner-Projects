#include <stdio.h>

int main() {
    printf("Good day! Let's calculate that GPA.\n");

    int c;
    printf("How many courses did you offer? ");
    if (scanf("%d", &c) != 1 || c <= 0) {
        printf("Invalid number of courses.\n");
        return 1;
    }

    // VLA (valid in C99+). Use malloc if you prefer portability.
    int units[c];
    char grades[c];
    char course[50];

    int totalUnits = 0;
    float totalPoints = 0.0f;

    for (int i = 0; i < c; i++) {
        printf("\nEnter details for course %d:\n", i + 1);

        printf("Course code: ");
        scanf("%49s", course);               // limit input to avoid overflow

        printf("Number of units: ");
        while (scanf("%d", &units[i]) != 1) { // input validation
            printf("Please enter a valid integer for units: ");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) ; // clear line
        }

        printf("Grade (A–F): ");
        scanf(" %c", &grades[i]); // <-- note the leading space; crucial!

        int gradePoint;
        switch (grades[i]) {
            case 'A': case 'a': gradePoint = 5; break;
            case 'B': case 'b': gradePoint = 4; break;
            case 'C': case 'c': gradePoint = 3; break;
            case 'D': case 'd': gradePoint = 2; break;
            case 'E': case 'e': gradePoint = 1; break;
            case 'F': case 'f': gradePoint = 0; break;
            default:
                printf("Invalid grade entered, counting as 0.\n");
            gradePoint = 0;
        }

        totalUnits += units[i];
        totalPoints += gradePoint * units[i];
    }

    if (totalUnits == 0) {
        printf("Total units is zero — cannot compute GPA.\n");
    } else {
        float gpa = totalPoints / totalUnits;
        printf("\n==============================\n");
        printf("Your GPA is: %.2f\n", gpa);
        printf("==============================\n");
    }

    return 0;
}
