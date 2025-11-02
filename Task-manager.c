//
// Created by robin on 11/2/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==============================
// Define the structure of a Task
// ==============================
typedef struct {
    char title[50];
    char description[200];
    int status;  // 0 = not completed, 1 = completed
} Task;

// ==============================
// Define the Linked List Node
// Each node holds one Task and a pointer to the next node
// ==============================
typedef struct Node {
    Task task;
    struct Node* next;
} Node;

// ==============================
// Function to create a new node dynamically
// ==============================
Node* createNode(Task newTask) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // allocate memory for new node
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->task = newTask; // copy task data into node
    newNode->next = NULL;    // initialize next pointer
    return newNode;
}

// ==============================
// Function to add a new task at the end of the linked list
// ==============================
void addTask(Node** head) {
    Task newTask;

    // Get task details from user
    printf("\nEnter the task title: ");
    fgets(newTask.title, sizeof(newTask.title), stdin);
    newTask.title[strcspn(newTask.title, "\n")] = 0; // remove newline

    printf("Enter the task description: ");
    fgets(newTask.description, sizeof(newTask.description), stdin);
    newTask.description[strcspn(newTask.description, "\n")] = 0;

    newTask.status = 0; // default = not completed

    // Create new node
    Node* newNode = createNode(newTask);

    // If list is empty, make new node the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Otherwise, traverse to the end and append
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Task added successfully!\n");
}

// ==============================
// Function to view all tasks
// ==============================
void viewTasks(Node* head) {
    if (head == NULL) {
        printf("\nNo tasks available.\n");
        return;
    }

    Node* temp = head;
    int count = 1;

    printf("\n----- All Tasks -----\n");
    while (temp != NULL) {
        printf("\nTask #%d\n", count);
        printf("Title: %s\n", temp->task.title);
        printf("Description: %s\n", temp->task.description);
        printf("Status: %s\n", temp->task.status ? " Completed" : " Not Completed");
        temp = temp->next;
        count++;
    }
}

// ==============================
// Function to mark a task as completed
// ==============================
void markTaskCompleted(Node* head) {
    if (head == NULL) {
        printf("No tasks to update.\n");
        return;
    }

    int taskNumber;
    printf("Enter the task number to mark as completed: ");
    scanf("%d", &taskNumber);
    getchar(); // clear newline

    Node* temp = head;
    int count = 1;

    while (temp != NULL) {
        if (count == taskNumber) {
            temp->task.status = 1;
            printf("Task '%s' marked as completed!\n", temp->task.title);
            return;
        }
        temp = temp->next;
        count++;
    }

    printf("Invalid task number.\n");
}

// ==============================
// Function to delete a specific task
// ==============================
void deleteTask(Node** head) {
    if (*head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }

    int taskNumber;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNumber);
    getchar(); // clear newline

    Node* temp = *head;
    Node* prev = NULL;
    int count = 1;

    // If deleting the first node
    if (taskNumber == 1) {
        *head = temp->next;
        free(temp);
        printf("Task #1 deleted successfully.\n");
        return;
    }

    // Traverse to the node before the one we want to delete
    while (temp != NULL && count != taskNumber) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If task number invalid
    if (temp == NULL) {
        printf(" Invalid task number.\n");
        return;
    }

    prev->next = temp->next; // unlink node
    free(temp);              // free memory
    printf(" Task #%d deleted successfully.\n", taskNumber);
}

// ==============================
// Function to free all allocated memory (clean up before exit)
// ==============================
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// ==============================
// MAIN FUNCTION
// ==============================
int main() {
    Node* head = NULL;  // start with an empty list
    int choice;

    printf("Welcome to Robin's Task Manager!\n");

    do {
        printf("\n=========================\n");
        printf("1. Add a new task\n");
        printf("2. View all tasks\n");
        printf("3. Mark a task as completed\n");
        printf("4. Delete a task\n");
        printf("5. Exit\n");
        printf("=========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addTask(&head);
                break;
            case 2:
                viewTasks(head);
                break;
            case 3:
                markTaskCompleted(head);
                break;
            case 4:
                deleteTask(&head);
                break;
            case 5:
                printf("Saving and exiting... \n");
                break;
            default:
                printf("⚠Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    freeList(head); // cleanup before exit
    return 0;
}
