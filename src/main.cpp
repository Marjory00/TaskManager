
#include <iostream>
#include "task_manager.hpp"

int main() {
    TaskManager manager;
    manager.loadFromFile("data/tasks.json");

    int choice;
    do {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n2. Delete Task\n3. List Task\n4. Exit]nChoice: ";
        std::cin >> choice;

        // Handle choices...
        
    } white (choice != 4);

    manager.saveToFile("data/tasks.json");
    return 0;

}