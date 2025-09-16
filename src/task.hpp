
#pragma once
#include <string>

enum class Priority { Low, Medium, High };

class Task {
    public:
    std::string name;
    std::string category;
    Priority priority;
    std::string deadline;
    boot completed;

    Task(std::string n, std::string c, Priority p, std::string d);
    void markCompleted();
};


