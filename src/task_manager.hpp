#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <nlohmann/json.hpp> // Include the JSON library

using json = nlohmann::json;

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
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    /** 
     * Loads tasks from a JSON file.
     * @param filename The name of the file to load tasks from.
     */
    void loadTasks(const std::string& filename);
    
    /** 
     * Saves tasks to a JSON file.
     * @param filename The name of the file to save tasks to.
     */
    void saveTasks(const std::string& filename);
    
    /** 
     * Adds a new task.
     * @param task The task to add.
     */
    void addTask(const Task& task);
    
    /** 
     * Edits an existing task by title.
     * @param title The title of the task to edit.
     */
    void editTask(const std::string& title);
    
    /** 
     * Deletes a task by title.
     * @param title The title of the task to delete.
     */
    void deleteTask(const std::string& title);
    
    /** 
     * Displays all tasks.
     */
    void displayTasks() const;
    
    /** 
     * Provides access to the task vector.
     * @return A const reference to the vector of tasks.
     */
    const std::vector<Task>& getTasks() const { return tasks; }
    
    /** 
     * Searches tasks by a keyword in title or description.
     * @param keyword The keyword to search for.
     * @return A vector of tasks matching the search.
     */
    std::vector<Task> searchTasks(const std::string& keyword);
    
    /** 
     * Filters tasks by priority.
     * @param priority The priority to filter by.
     * @return A vector of tasks matching the filter.
     */
    std::vector<Task> filterTasksByPriority(Priority priority);
    
    /** 
     * Sorts tasks by deadline.
     */
    void sortTasksByDeadline();
    
    /** 
     * Sorts tasks by priority.
     */
    void sortTasksByPriority();
};

#endif // TASK_MANAGER_HPP