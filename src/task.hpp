#ifndef TASK_HPP
#define TASK_HPP

#include <string>

struct Task {
    std::string title;
    std::string description;
    std::string priority; // Low, Medium, High
    std::string deadline; // YYYY-MM-DD
    std::string category; // Task category
};

#endif // TASK_HPP