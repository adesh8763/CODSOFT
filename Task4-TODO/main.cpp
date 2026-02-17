#include <iostream>
#include <string>

int ids[100];
std::string titles[100];
bool done[100];
int count = 0;

void showTasks() {
    if (count == 0) {
        std::cout << "No tasks!" << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        std::cout << ids[i] << ". ";
        if (done[i]) {
            std::cout << "[DONE] ";
        } else {
            std::cout << "[    ] ";
        }
        std::cout << titles[i] << std::endl;
    }
}

void addTask() {
    std::cout << "Enter task title: ";
    std::string title;
    std::getline(std::cin, title);
    ids[count] = count + 1;
    titles[count] = title;
    done[count] = false;
    count++;
    std::cout << "Task added!" << std::endl;
}

void markDone() {
    std::cout << "Enter task ID to mark as done: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            done[i] = true;
            std::cout << "Task marked as done!" << std::endl;
            return;
        }
    }
    std::cout << "Task not found!" << std::endl;
}

void deleteTask() {
    std::cout << "Enter task ID to delete: ";
    int id;
    std::cin >> id;
    std::cin.ignore();
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            for (int j = i; j < count - 1; j++) {
                ids[j] = ids[j + 1];
                titles[j] = titles[j + 1];
                done[j] = done[j + 1];
            }
            count--;
            std::cout << "Task deleted!" << std::endl;
            return;
        }
    }
    std::cout << "Task not found!" << std::endl;
}

int main() {
    std::cout << "Welcome to Sakurti TODO! " << std::endl;

    int choice;

    while (true) {
        std::cout << std::endl;
        std::cout << "1. Show tasks" << std::endl;
        std::cout << "2. Add task" << std::endl;
        std::cout << "3. Mark task as done" << std::endl;
        std::cout << "4. Delete task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            showTasks();
        } else if (choice == 2) {
            addTask();
        } else if (choice == 3) {
            markDone();
        } else if (choice == 4) {
            deleteTask();
        } else if (choice == 5) {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice, try again." << std::endl;
        }
    }

    return 0;
}