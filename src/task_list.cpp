#include "task_list.hpp"
#include <iostream>

using namespace std;

bool isValidPriority(int priority) {
    // TODO: Return true when priority is from 1 to 5.
   if (priority >= 1 && priority <= 5) {
    return true;
   } 
    return false;
}

Task createTask(string description, int priority) {
    Task task;

    // TODO:
    // Store the description.
    // Store the priority if valid; otherwise store 1.
    // New tasks should start as not completed.
task.description = description;

if (isValidPriority(priority)) {
    task.priority = priority;
} 
else
{
    task.priority = 1;
}
task.completed = false;
    return task;
}

void insertFront(TaskNode*& head, Task task) {
    // TODO:
    // Dynamically allocate a new TaskNode.
    // Store task in the node.
    // Point the new node to the old head.
    // Update head.
    TaskNode* newNode = new TaskNode;

    newNode->data = task;

    newNode->next = head;

    head = newNode;
}

int countTasks(const TaskNode* head) {
    // TODO: Traverse the list and count nodes.
    int count = 0;

    const TaskNode* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

TaskNode* findTask(TaskNode* head, string description) {
    // TODO:
    // Traverse the list.
    // Return the first node whose task description matches.
    // Return nullptr if not found.
    TaskNode* current = head;
    while (current != nullptr) {
        if (current->data.description == description) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool markTaskComplete(TaskNode* head, string description) {
    // TODO:
    // Find the task.
    // If found, set completed to true and return true.
    // Otherwise return false.
    TaskNode* task = findTask(head, description);

    if (task != nullptr) {
        task->data.completed = true;
        return true;
    }
    return false;
}

int removeCompletedTasks(TaskNode*& head) {
    // TODO:
    // Remove all completed tasks.
    // Return the number of removed nodes.
    // Be sure to handle completed tasks at the head of the list.
    int removed = 0;

    while (head != nullptr && head->data.completed) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
        removed++;
    }

    TaskNode* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->data.completed) {
            TaskNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            removed++;
        } 
        else {
            current = current->next;
        }
    }
    return removed;
}

void clearTasks(TaskNode*& head) {
    // TODO:
    // Delete every node in the list.
    // Set head to nullptr.
    while (head != nullptr) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

void printTask(const Task& task) {
    cout << task.description
         << " | priority " << task.priority
         << " | " << (task.completed ? "complete" : "not complete")
         << endl;
}

void printTasks(const TaskNode* head) {
    if (head == nullptr) {
        cout << "No tasks." << endl;
        return;
    }

    cout << "Task List:" << endl;

    const TaskNode* current = head;

    while (current != nullptr) {
        printTask(current->data);
        current = current->next;
    }

    cout << "Total tasks: " << countTasks(head) << endl;
}
