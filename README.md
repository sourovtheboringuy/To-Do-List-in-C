To-Do List Application in C
Overview

The To-Do List Application is a console-based program written in C for managing personal to-do lists efficiently. It supports multiple users, allowing each user to maintain their own to-do list, with persistent storage that ensures tasks are saved across sessions. This lightweight tool offers a simple menu to add, view, mark tasks as done, and delete tasks.
Features

    Multi-User Support: Each user gets their own to-do list file (<username>_tasks.txt), ensuring personalized task management.
    Add Tasks: Add tasks to your to-do list effortlessly.
    View Tasks: Display all tasks with their completion status (pending or completed).
    Mark Tasks as Done: Easily mark tasks as completed.
    Delete Tasks: Remove tasks when no longer needed.
    Persistent Storage: Tasks are saved in text files and reloaded automatically for future sessions.
    Case-Insensitive Usernames: Usernames are converted to lowercase for consistent file naming.

How It Works

    User Identification:
        Specify whether you're a "new" or "existing" user.
        Enter your username (case-insensitive).
        A unique task file is created or loaded based on the username.

    To-Do List Management Menu:
        View Tasks: Lists all tasks with their status ([ ] for pending, [X] for done).
        Add Task: Prompts you to enter a new task to add to the list.
        Mark Task as Done: Marks a selected task as completed.
        Delete Task: Removes a selected task from the list.

    Data Storage:
        All tasks are saved in a user-specific text file (<username>_tasks.txt).
        The application ensures previous task data is preserved.

Example Usage
Starting the Program

Are you a new or existing user? (new/existing): existing
Enter your name: JohnDoe

Menu Options

Menu:
1. View Tasks
2. Add Task
3. Mark Task as Done
4. Delete Task
5. Exit
Enter your choice: 1

1. [ ] Finish C project
2. [X] Submit report

Adding a Task

Enter the task description: Buy groceries
Task added successfully!

Marking a Task as Done

Enter the task number to mark as done: 1
Task marked as done!

Deleting a Task

Enter the task number to delete: 2
Task deleted successfully!

Setup and Compilation

Requirements

    A C compiler (e.g., GCC)
    Compatible with Linux, macOS, and Windows (via MinGW or similar tools)

Contributions

Contributions are welcome! If you'd like to improve this program, feel free to submit a pull request or open an issue.
