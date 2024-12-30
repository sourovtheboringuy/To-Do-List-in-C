#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 100
#define MAX_TASK_LEN 256
#define MAX_NAME_LEN 50

typedef struct {
    char description[MAX_TASK_LEN];
    int is_done;
} Task;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void load_tasks(Task tasks[], int *task_count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return;

    *task_count = 0;
    while (fscanf(file, "%255[^\n] %d\n", tasks[*task_count].description, &tasks[*task_count].is_done) != EOF) {
        (*task_count)++;
    }

    fclose(file);
}

void save_tasks(Task tasks[], int task_count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) return;

    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%s %d\n", tasks[i].description, tasks[i].is_done);
    }

    fclose(file);
}

void add_task(Task tasks[], int *task_count, const char *filename) {
    if (*task_count >= MAX_TASKS) return;

    printf("Enter the task description: ");
    getchar();
    fgets(tasks[*task_count].description, MAX_TASK_LEN, stdin);
    tasks[*task_count].description[strcspn(tasks[*task_count].description, "\n")] = 0;
    tasks[*task_count].is_done = 0;

    (*task_count)++;
    save_tasks(tasks, *task_count, filename);
}

void view_tasks(Task tasks[], int task_count) {
    if (task_count == 0) return;

    for (int i = 0; i < task_count; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].is_done ? 'X' : ' ', tasks[i].description);
    }
}

void mark_task_done(Task tasks[], int task_count, const char *filename) {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nCurrent Tasks:\n");
    view_tasks(tasks, task_count);

    int task_num;
    printf("Enter the task number to mark as done: ");
    scanf("%d", &task_num);

    if (task_num < 1 || task_num > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    tasks[task_num - 1].is_done = 1;
    save_tasks(tasks, task_count, filename);
    printf("Task marked as done!\n");
}

void delete_task(Task tasks[], int *task_count, const char *filename) {
    if (*task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nCurrent Tasks:\n");
    view_tasks(tasks, *task_count);

    int task_num;
    printf("Enter the task number to delete: ");
    scanf("%d", &task_num);

    if (task_num < 1 || task_num > *task_count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = task_num - 1; i < *task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*task_count)--;
    save_tasks(tasks, *task_count, filename);
    printf("Task deleted successfully!\n");
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;
    char username[MAX_NAME_LEN];
    char filename[MAX_NAME_LEN + 10];
    printf("Welcome to TO-DO list Application\n");
    printf("Are you a new or existing user? (new/existing): ");
    char user_type[10];
    scanf("%9s", user_type);
    getchar();

    printf("Enter your name: ");
    fgets(username, MAX_NAME_LEN, stdin);
    username[strcspn(username, "\n")] = 0;
    to_lowercase(username);

    snprintf(filename, sizeof(filename), "%s_tasks.txt", username);

    if (strcmp(user_type, "new") == 0) {
        FILE *file = fopen(filename, "r");
        if (file != NULL) {
            fclose(file);
        }
    }

    load_tasks(tasks, &task_count, filename);

    int choice;
    do {
        printf("\nMenu:\n1. View Tasks\n2. Add Task\n3. Mark Task as Done\n4. Delete Task\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_tasks(tasks, task_count);
                break;
            case 2:
                add_task(tasks, &task_count, filename);
                break;
            case 3:
                mark_task_done(tasks, task_count, filename);
                break;
            case 4:
                delete_task(tasks, &task_count, filename);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
