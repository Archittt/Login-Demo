#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registration();
void login();

int main() {
    int choice;

    cout << "Welcome to the login and registration system!" << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    return 0;
}

void registration() {
    string username, password;

    cout << "Please enter a username: ";
    cin >> username;
    cout << "Please enter a password: ";
    cin >> password;

    ofstream outfile;
    outfile.open("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration complete!" << endl;
}

void login() {
    string username, password, line;
    bool found = false;

    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    ifstream infile;
    infile.open("users.txt", ios::in);
    while (infile >> line) {
        if (line == username) {
            infile >> line;
            if (line == password) {
                found = true;
                break;
            }
        }
    }
    infile.close();

    if (found) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password!" << endl;
    }
}
