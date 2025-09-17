#include "task_manager.hpp"

void TaskManager::loadTasks(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        for (const auto& item : j) {
            tasks.push_back(item.get<Task>());
        }
        std::cout << "Tasks loaded successfully.\n";
    } else {
        std::cerr << "Error opening file for loading tasks.\n";
    }
}

void TaskManager::saveTasks(const std::string& filename) {
    json j = tasks;
    std::ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);
        std::cout << "Tasks saved successfully.\n";
    } else {
        std::cerr << "Error opening file for saving tasks.\n";
    }
}

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
    std::cout << "Task added successfully.\n";
}

void TaskManager::editTask(const std::string& title) {
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

void TaskManager::deleteTask(const std::string& title) {
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

void TaskManager::displayTasks() const {
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