#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isValidUsername(const string &username) {
    if (username.size() < 3) return false;
    for (char c : username) {
        if (!isalnum(static_cast<unsigned char>(c)) && c != '_' && c != '.') {
            return false;
        }
    }
    return true;
}

bool isValidPassword(const string &password) {
    if (password.size() < 6) return false;

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : password) {
        if (isupper(static_cast<unsigned char>(c))) hasUpper = true;
        if (islower(static_cast<unsigned char>(c))) hasLower = true;
        if (isdigit(static_cast<unsigned char>(c))) hasDigit = true;
    }
    return hasUpper && hasLower && hasDigit;
}

bool usernameExists(const string &username) {
    ifstream fin("users.txt");
    if (!fin.is_open()) return false;

    string storedUser, storedPass;
    while (fin >> storedUser >> storedPass) {
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

bool registerUser() {
    string username, password, confirmPassword;

    cout << "\n----- USER REGISTRATION -----\n";
    cout << "Enter username: ";
    cin >> username;

    if (!isValidUsername(username)) {
        cout << "Error: Username must be at least 3 characters and contain only letters, digits, '_' or '.'\n";
        return false;
    }

    if (usernameExists(username)) {
        cout << "Error: Username already exists. Please choose another.\n";
        return false;
    }

    cout << "Enter password: ";
    cin >> password;
    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Error: Passwords do not match.\n";
        return false;
    }

    if (!isValidPassword(password)) {
        cout << "Error: Password must be at least 6 characters and contain uppercase, lowercase and digits.\n";
        return false;
    }

    ofstream fout("users.txt", ios::app);
    if (!fout.is_open()) {
        cout << "Error: Could not open users file for writing.\n";
        return false;
    }

    fout << username << " " << password << "\n";
    cout << "Registration successful! You can now log in.\n";
    return true;
}

bool loginUser() {
    string username, password;
    cout << "\n----- USER LOGIN -----\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream fin("users.txt");
    if (!fin.is_open()) {
        cout << "Error: No users registered yet.\n";
        return false;
    }

    string storedUser, storedPass;
    bool found = false;
    while (fin >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful! Welcome, " << username << ".\n";
        return true;
    } else {
        cout << "Invalid username or password.\n";
        return false;
    }
}

void showMenu() {
    cout << "\n===========================\n";
    cout << "  LOGIN & REGISTRATION     \n";
    cout << "===========================\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice = 0;
    bool running = true;

    while (running) {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            cout << "Exiting application. Goodbye!\n";
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
