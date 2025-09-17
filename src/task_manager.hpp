#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <nlohmann/json.hpp> // Include the JSON library

using json = nlohmann::json;

struct Task {
    std::string title;
    std::string description;
    std::string priority; // Low, Medium, High
    std::string deadline; // YYYY-MM-DD
    std::string category; // Task category
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void loadTasks(const std::string& filename);
    void saveTasks(const std::string& filename);
    void addTask(const Task& task);
    void editTask(const std::string& title);
    void deleteTask(const std::string& title);
    void displayTasks() const;
    std::vector<Task>& getTasks(); // Accessor for tasks
};

#endif // TASK_MANAGER_HPP