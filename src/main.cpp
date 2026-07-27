#include "task_list.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    TaskNode* head = nullptr;
    int choice = -1;

    cout << "Simple Linked Task List" << endl;

    do {
        cout << endl;
        cout << "1. Add task" << endl;
        cout << "2. Display tasks" << endl;
        cout << "3. Mark task complete" << endl;
        cout << "4. Remove completed tasks" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string description;
            int priority = 1;

            cout << "Enter description: ";
            cin.ignore(100, '\n');
            getline(cin, description);

            cout << "Enter priority 1-5: ";
            cin >> priority;

            while (!isValidPriority(priority)) {
                cout << "Invalid priority. Enter 1-5: ";
                cin >> priority;
            }

            insertFront(head, createTask(description, priority));
            cout << "Task added." << endl;

        } else if (choice == 2) {
            printTasks(head);

        } else if (choice == 3) {
            string description;

            cout << "Enter description to complete: ";
            cin.ignore(100, '\n');
            getline(cin, description);

            if (markTaskComplete(head, description)) {
                cout << "Task marked complete." << endl;
            } else {
                cout << "Task not found." << endl;
            }

        } else if (choice == 4) {
            int removed = removeCompletedTasks(head);
            cout << "Removed " << removed << " completed task(s)." << endl;

        } else if (choice == 0) {
            cout << "Goodbye!" << endl;

        } else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    clearTasks(head);

    return 0;
}
