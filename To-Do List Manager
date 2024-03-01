#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int num_tasks = 0;

void addTask(char task[]) {
    if (num_tasks < MAX_TASKS) {
        strcpy(tasks[num_tasks], task);
        num_tasks++;
        printf("Task added: %s\n", task);
    } else {
        printf("Error: Task list is full!\n");
    }
}

void removeTask(int index) {
    if (index >= 0 && index < num_tasks) {
        printf("Task removed: %s\n", tasks[index]);
        for (int i = index; i < num_tasks - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        num_tasks--;
    } else {
        printf("Error: Invalid task index!\n");
    }
}

void displayTasks() {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

int main() {
    char input[MAX_LENGTH];
    int choice, index;

    while (1) {
        printf("\nTodo List Manager\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task: ");
                scanf(" %[^\n]", input);
                addTask(input);
                break;
            case 2:
                printf("Enter task index: ");
                scanf("%d", &index);
                removeTask(index - 1);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
