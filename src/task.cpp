#include "task.hpp"

// Constructor to initialize Task with title and description
Task::Task(const std::string& title, const std::string& description)
    : title(title), description(description) {}

// Getter for title
std::string Task::getTitle() const {
    return title;
}

// Getter for description
std::string Task::getDescription() const {
    return description;
}