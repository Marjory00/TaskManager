
#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp> // Make sure to include the JSON library


using json = nlohmann::json;

struct Task {

    std::string title;
    std::string description;
    std::string priority; // Low, Medium, High
    std::string deadline; // YYYY-MM-DD
    std::string category; // Task category

};

// Global task list
std::vector<Task> tasks;

// Function declarations
void loadTasks();
void saveTasks();
void addTask();
void editTask();
void deleteTask();
void displayTasks();
void printMenu();


int main() {
    loadTasks(); // Load tasks from file

    
    int choice;
    do {
        printMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from input buffer


        switch (choice) {
            case 1: addTask(); break;
            case 2: editTask(); break;
            case 3: deleteTask(); break;
            case 4: displayTasks(); break;
            case 5: saveTasks(); break;
            case 6: std::cout << "Exiting the application.\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;

            }

        } while (choice != 6);

        return 0;
    }


    // Function to load tasks from JSON file

     void loadTasks() {
        std::ifstream file("tasks.json");
        if (file.is_open()) }
        json j;
        file >> j;
        for (const auto& item : j) {
            tasks.push_back(item.get<Task>());

        }
     }
    }

    // Function to save tasks to JSON file
    void saveTasks() {
        json j = tasks;
        std::ofstream file("tasks.json");
        if (file.is_open()) }
        file << j.dump(4);
        std::cout << "Tasks saved succesfully.\n";

    }
}

// Function to add a task
void addTask() {
    Task newTask;
    std::cout << "Enter task title: ";
    std::getline(std::cin, newTask.title);
    std::cout << "Enter task description: ";
    std::getline(std::cin, newTask.description);
    std::cout << "Enter priority (Low, Medium, High): ";
    std::getline(std::cin, newTask.priority);
    std::cout << "Enter deadline (YYYY-MM-DD): ";
    std::getline(std::cin, newTask.deadline);
    std::cout << "Enter category: ";
    std::getline(std::cin, newTask.category);
    
    tasks.push_back(newTask);
    std::cout << "Task added successfully.\n";
}

// Function to edit a task
void editTask() {
    std::string title;
    std::cout << "Enter the title of the task to edit: ";
    std::getline(std::cin, title);

    for (auto& task : tasks) {
        if (task.title == title) {
            std::cout << "Editing task: " << task.title << "\n";
            std::cout << "Enter new description (leave blank to keep current): ";
            std::string desc;
            std::getline(std::cin, desc);
            if (!desc.empty()) task.description = desc;

            std::cout << "Enter new priority (leave blank to keep current): ";
            std::string priority;
            std::getline(std::cin, priority);
            if (!priority.empty()) task.priority = priority;

            std::cout << "Enter new deadline (leave blank to keep current): ";
            std::string deadline;
            std::getline(std::cin, deadline);
            if (!deadline.empty()) task.deadline = deadline;

            std::cout << "Enter new category (leave blank to keep current): ";
            std::string category;
            std::getline(std::cin, category);
            if (!category.empty()) task.category = category;

            std::cout << "Task edited successfully.\n";
            return;
        }
    }
    std::cout << "Task not found.\n";
}

// Function to delete a task
void deleteTask() {
    std::string title;
    std::cout << "Enter the title of the task to delete: ";
    std::getline(std::cin, title);

    auto it = std::remove_if(tasks.begin(), tasks.end(), [&title](const Task& task) {
        return task.title == title;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task deleted successfully.\n";
    } else {
        std::cout << "Task not found.\n";
    }
}

// Function to display all tasks
void displayTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (const auto& task : tasks) {
        std::cout << "Title: " << task.title << "\n"
                  << "Description: " << task.description << "\n"
                  << "Priority: " << task.priority << "\n"
                  << "Deadline: " << task.deadline << "\n"
                  << "Category: " << task.category << "\n\n";
    }
}

// Function to print the menu
void printMenu() {
    std::cout << "\n--- Task Manager Menu ---\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Edit Task\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Display Tasks\n";
    std::cout << "5. Save Tasks\n";
    std::cout << "6. Exit\n";
}