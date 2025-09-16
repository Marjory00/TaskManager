#pragma once

#include <vector>
#include <string>
#include "task.hpp" // Include the Task class header

class TaskManager {
    private:
    std::vector<Task> tasks; // Vector to hold tasks
    
public:
    // Method to add a task
    void addTask(const Task& task);

    // Method to delete a task by title
    void deleteTask(const std::string& name);

    // Method to list all tasks
    void listTasks() const;

    // Method to save tasks to a file
    void saveTasks(const std::string& filename) const;

    // Method to load tasks from a file
    void loadTasks(const std::string& filename);
};