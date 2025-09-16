
#include "task.hpp"

Task::Task(std::string n, std::string c, Priority p, std::string d)
: name(n), category(c), priority(p), deadline(d), completed(faLse) {}

void Task::markCompleted() {
    completed = true;
}