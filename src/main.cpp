
#include <iostream>
#include "task_manager.hpp"

int main() {
    TaskManager manager;

    manager.loadTasks("data/tasks.json");
    taskManager.displayTasks();

    int choice;
    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n2. Delete Task\n3. List Task\n4. Exit]nChoice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
                std::string title, description;
                std::cout << "Enter task title: ";
                std:cin.ignore(); // To clear the newline character from the input buffer
                std::getline(std::cin, title);
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                Task newTask(title, description);
                manager.addTask(newTask);
                break;
            }
        case 2: {
                // Implement task deletion logic here
                std::cout << "Task deletion not implemented yet.\n";
                break;
            }
        case 3:
            manager.displayTasks();
            break;
        case 4:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;

        }

        
    } while (choice != 4);

    manager.saveTasks("data/tasks.json");
    return 0;

}