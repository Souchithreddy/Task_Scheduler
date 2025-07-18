#include<bits/stdc++.h>
using namespace std;

struct task{
    int id;
    string description;
    string duedate;
    bool completed;
    int priority;
};

vector<task>tasks;

void addTask(int id, string description, string duedate,int priority) {
    task newTask;
    newTask.id = id;
    newTask.description = description;
    newTask.duedate = duedate;
    newTask.completed = false;
    newTask.priority = priority;
    tasks.push_back(newTask);
}

void viewTasks(){
    if(tasks.empty()){
        printf("No tasks available.\n");
        return;
    }
    printf("Tasks:\n");
    for(auto& t : tasks){
        printf("ID: %d | Description: %s | Due Date: %s | Completed: %s | Priority: %d\n", 
               t.id, t.description.c_str(), t.duedate.c_str(), 
               t.completed ? "Yes" : "No", t.priority);
    }   
}
void markcompleted(){
    int id;
    printf("Enter task ID to mark as completed: ");
    cin>>id;
    for(auto &t:tasks){
        if(t.id==id){
            t.completed=true;
            cout<< "Task ID " << id << " marked as completed.\n";
            return;
        }   
    }   
    cout<< "Task ID " << id << " not found.\n";
}

void deletetask(){
    int id;
    printf("Enter task ID to delete: ");
    cin >> id;
    auto it = remove_if(tasks.begin(), tasks.end(), [id](task& t) { return t.id == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task ID " << id << " deleted successfully.\n";
    } else {
        cout << "Task ID " << id << " not found.\n";
    }
}

void viewTaskByPriority(int priority) {
    bool found = false;
    printf("Tasks with priority %d:\n", priority);
    for (const auto& t : tasks) {
        if (t.priority == priority) {
            printf("ID: %d | Description: %s | Due Date: %s | Completed: %s\n",
                   t.id, t.description.c_str(), t.duedate.c_str(),
                   t.completed ? "Yes" : "No");
            found = true;
        }
    }
    if (!found) {
        printf("No tasks found with priority %d.\n", priority);
    }
}

int main() {
    int choice;
    do {
        printf("Task Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. View Tasks by Priority\n");
        printf("6. view highest priority task\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;

        switch (choice) {
            case 1: {
                int id,priority;
                string description, duedate;
                cout << "Enter task ID: ";
                cin >> id;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                cout << "Enter due date (YYYY-MM-DD): ";
                getline(cin, duedate);
                cout << "Enter task priority (1-5): ";
                cin >> priority;
                addTask(id, description, duedate,priority);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3:
                markcompleted();
                break;
            case 4:
                deletetask();
                break;
            case 5: {
                int priority;
                cout << "Enter priority level to view tasks (1-5): ";
                cin >> priority;
                if (priority < 1 || priority > 5) {
                    cout << "Invalid priority level. Please enter a value between 1 and 5.\n";
                } else {
                    viewTaskByPriority(priority);
                }
                break;
            }
            case 6: {
                if (tasks.empty()) {
                    cout << "No tasks available.\n";
                    break;
                }
                auto highestPriorityTask = min_element(tasks.begin(), tasks.end(), [](const task& a, const task& b) {
        return a.priority < b.priority;  
    });
                cout << "Highest Priority Task:\n";
                cout << "ID: " << highestPriorityTask->id 
                     << " | Description: " << highestPriorityTask->description 
                     << " | Due Date: " << highestPriorityTask->duedate 
                     << " | Completed: " << (highestPriorityTask->completed ? "Yes" : "No") 
                     << " | Priority: " << highestPriorityTask->priority << endl;
                break;
            }
            case 7:
                cout << "Exiting Task Scheduler.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}