
const fs = require('fs');
const readline = require('readline');

const TASKS_FILE = 'tasks.json';

// Function to load tasks from a JSON file
function loadTasks() {
    if (fs.existsSync(TASKS_FILE)) {
        const data = fs.readFileSync(TASKS_FILE);
        return JSON.parse(data);
    }
    return [];
}

// Function to save tasks to a JSON file
function saveTasks(tasks) {
    fs.writeFileSync(TASKS_FILE, JSON.stringify(tasks, null, 4));
}

// Function to display tasks
function displayTasks(tasks) {
    if (tasks.length === 0) {
        console.log("No tasks available.");
        return;
    }
    tasks.forEach((task, index) => {
        console.log(`${index + 1}. Title: ${task.title}`);
        console.log(`   Description: ${task.description}\n`);
    });
}

// Function to add a task
function addTask(tasks, title, description) {
    tasks.push({ title, description });
    saveTasks(tasks);
    console.log(`Task "${title}" added successfully.`);
}

// Function to delete a task
function deleteTask(tasks, title) {
    const index = tasks.findIndex(task => task.title === title);
    if (index !== -1) {
        tasks.splice(index, 1);
        saveTasks(tasks);
        console.log(`Task "${title}" deleted successfully.`);
    } else {
        console.log(`Task "${title}" not found.`);
    }
}

// Command-line interface
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function main() {
    const tasks = loadTasks();

    console.log("Task Manager");
    console.log("1. List Tasks");
    console.log("2. Add Task");
    console.log("3. Delete Task");
    console.log("4. Exit");

    rl.question("Choose an option: ", (choice) => {
        switch (choice) {
            case '1':
                displayTasks(tasks);
                break;
            case '2':
                rl.question("Enter task title: ", (title) => {
                    rl.question("Enter task description: ", (description) => {
                        addTask(tasks, title, description);
                        main(); // Restart the menu
                    });
                });
                return; // Prevent main from running again immediately
            case '3':
                rl.question("Enter task title to delete: ", (title) => {
                    deleteTask(tasks, title);
                    main(); // Restart the menu
                });
                return; // Prevent main from running again immediately
            case '4':
                console.log("Exiting the program.");
                rl.close();
                return;
            default:
                console.log("Invalid option. Please try again.");
                main(); // Restart the menu
                return; // Prevent main from running again immediately
        }
        rl.close();
    });
}

main();