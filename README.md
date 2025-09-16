# 🗂 Task Manager Application (C++)

A console-based task manager built in C++ that allows users to manage tasks with priorities, deadlines, and categories.

## ✨ Features
- Add, edit, delete tasks
- Set priorities (Low, Medium, High)
- Assign deadlines (YYYY-MM-DD)
- Organize tasks by category
- Save tasks locally in JSON format

## 🛠 Requirements
- C++11 or later
- Visual Studio Code
- Git
- [nlohmann/json](https://github.com/nlohmann/json) for JSON handling

## 🚀 Getting Started
1. Clone the repo
2. Add `json.hpp` to `include/`
3. Compile with:
g++ -std=c++11 src/*.cpp -Iinclude -o task_manager
4. Run:
## 🔒 Privacy
Sensitive logic (e.g., encryption, user credentials) is modularized and excluded from public commits via `.gitignore`.

## 📄 License
MIT License
