
#pragma once
#include <vector>
#include <string>
#include "task.hpp" // Make sure to include the Task class header



class TaskManager {
    private:
    std::vector<Task> tasks;
    public:
    void addTask(const Task& task);
    void deleteTask(const std::string& name);
    void listTasks() const;
    void saveTasks(const std::string& filename) const; // Changed to saveTasks for consistency
    void loadTasks(const std::string& filename); // Changed to loadTasks for consistency

};