#ifndef TASK_HPP
#define TASK_HPP

#include <string>

class Task {
public:
    // Constructor
    Task(const std::string& title, const std::string& description);

    // Getter for title
    std::string getTitle() const;

    // Getter for description
    std::string getDescription() const;

private:
    std::string title;       // Title of the task
    std::string description; // Description of the task
};

#endif // TASK_HPP