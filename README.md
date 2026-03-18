
***

## README – Login and Registration System

```markdown
# Login and Registration System (C++)

This project is a simple **Login and Registration System** implemented in C++.  
It demonstrates basic file handling, input validation, and a menu-driven console interface.

## Features

- Register new users with username and password.
- Validate username and password (length and characters).
- Check for duplicate usernames.
- Store credentials in a text file.
- Login with existing credentials.
- Display clear success and error messages.

## System Design

### 1. Registration

- Prompts for:
  - `username`
  - `password`
  - `confirm password`
- Checks:
  - Username length ≥ 3
  - Username contains only letters, digits, `_` or `.`
  - Password length ≥ 6
  - Password has at least one uppercase, one lowercase, and one digit
  - Password and confirm password match
  - Username must not already exist in storage file

If all checks pass, the system appends `username password` to `users.txt`.

### 2. Login

- Prompts for:
  - `username`
  - `password`
- Reads credentials from `users.txt`.
- If a matching pair is found, login is successful; otherwise, login fails.

## Technologies Used

- Language: C++
- Standard Library: `<iostream>`, `<fstream>`, `<string>`, `<cctype>`

## File Structure

- `main.cpp` – Contains:
  - `isValidUsername()` – username validation logic
  - `isValidPassword()` – password validation logic
  - `usernameExists()` – checks for duplicate username in file
  - `registerUser()` – handles registration process
  - `loginUser()` – handles login process
  - Menu loop in `main()`
- `users.txt` – Simple text file used as a mini “database” for credentials.

## How to Compile and Run

```bash
g++ main.cpp -o login_system
./login_system
