#include "task_manager.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "json.hpp" // Include the JSON library

using json = nlohmann::json;

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::deleteTask(const std::string& name) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
        [&name](const Task& task) { return task.getTitle() == name; });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "Task \"" << name << "\" deleted successfully.\n";
    } else {
        std::cout << "Task \"" << name << "\" not found.\n";
    }
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (const auto& task : tasks) {
        std::cout << "Title: " << task.getTitle() << "\n";
        std::cout << "Description: " << task.getDescription() << "\n\n";
    }
}

void TaskManager::saveTasks(const std::string& filename) const {
    json j;
    for (const auto& task : tasks) {
        j.push_back({{"title", task.getTitle()}, {"description", task.getDescription()}});
    }

    std::ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);
        file.close();
    } else {
        std::cerr << "Error opening file for writing: " << filename << "\n";
    }
}

void TaskManager::loadTasks(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << "\n";
        return;
    }

    json j;
    file >> j;
    tasks.clear(); // Clear existing tasks before loading

    for (const auto& item : j) {
        tasks.emplace_back(item["title"], item["description"]);
    }
}