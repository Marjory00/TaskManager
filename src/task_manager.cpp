
#pragma once
#include <vector>

class TaskManager {
    private:
    std::vector<Task> tasks;
    public:
    void addTask(const Task& task);
    void deleteTask(const std::string& name);
    void listTasks() const;
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

};