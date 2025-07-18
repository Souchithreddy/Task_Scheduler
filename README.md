# 🗂 Task Scheduler (C++ Console App)

A simple command-line Task Scheduler built in C++. It allows users to manage tasks with functionality to add, view, delete, and mark tasks as completed. Each task has a unique ID, description, due date, completion status, and priority level.

---

##  Features

-  Add a new task with details (ID, description, due date, priority)
-  View all tasks with their status
-  Mark any task as completed
-  Delete a task by its ID
-  Filter tasks based on priority (1-5)
-  View the **highest priority task** instantly

---

##  How It Works

Each task is stored in a `vector<task>`. The app presents a menu-driven interface where the user can interact using numbered choices. The program continues running in a loop until the user chooses to exit.

###  Task Structure
```cpp
struct task {
    int id;
    string description;
    string duedate;
    bool completed;
    int priority;
};

Task Scheduler Menu:
1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Delete Task
5. View Tasks by Priority
6. View Highest Priority Task
7. Exit
Enter your choice:


**Notes**
-Priority levels are from 1 (highest) to 5 (lowest)
-Due date is input as a string (e.g., "2025-07-20")
-The app currently runs in memory; no persistent storage is used
-Duplicate IDs are not checked (can be added as enhancement)

**Future Enhancements**
- Save tasks to a file (persistent storage)
- Interactive UI using ncurses or similar libraries
- Search tasks by keyword or date
- Sort tasks by due date or priority

Pull requests are welcome! For major changes, please open an issue first to discuss what you'd like to change.


