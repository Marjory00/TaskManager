#ifndef TASK_HPP
#define TASK_HPP

#include <string>

// Enum for task priority
enum class Priority {
    Low,
    Medium,
    High
};

struct Task {
    std::string title;
    std::string description;
    Priority priority; // Use enum for priority
    std::string deadline; // YYYY-MM-DD
    std::string category; // Task category

    // Constructor
    Task(const std::string& t, const std::string& d, Priority p, const std::string& dl, const std::string& c)
        : title(t), description(d), priority(p), deadline(dl), category(c) {}
};

#endif // TASK_HPP