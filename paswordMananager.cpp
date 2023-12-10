#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100; // Maximum number of credentials

class PasswordManager {
public:
    virtual void addPassword(const string& website, const string& username, const string& password) = 0;
    virtual void displayPasswords() const = 0;
    virtual ~PasswordManager() {}
};

class SimplePasswordManager : public PasswordManager {
private:
    string websites[MAX_SIZE];
    string usernames[MAX_SIZE];
    string passwords[MAX_SIZE];
    int count = 0;

public:
    void addPassword(const string& website, const string& username, const string& password) {
        if (count < MAX_SIZE) {
            websites[count] = website;
            usernames[count] = username;
            passwords[count] = password;
            cout << "Password added successfully for " << website << endl;
            count++;
        } else {
            cout << "Maximum credentials limit reached. Cannot add more passwords." << endl;
        }
    }

    void displayPasswords() const  {
        cout << "Stored Passwords:" << endl;
        for (int i = 0; i < count; ++i) {
            cout << "\tWebsite: " << websites[i] << ",\tUsername: " << usernames[i] << ",\tPassword: " << passwords[i] << endl;
        }
    }
};

int main() {
    SimplePasswordManager passwordManager;
    int choice = 0;

    for (; choice != 3;) {
        cout << "\nPassword Manager Menu:\n"
             << "1. Add Password\n"
             << "2. Display Passwords\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string website, username, password;
                cout << "\nEnter website: ";
                cin.ignore(); // Clear any previous newline character
                getline(cin, website); //The ws manipulator is used to skip whitespace characters (like spaces, tabs, and newline) before reading the actual input
                cout << "Enter username: ";
                getline(cin,username);
                cout << "Enter password: ";
                getline(cin,password);
                passwordManager.addPassword(website, username, password);
                break;
            }
            case 2:
            	cout << "\n"<<endl;
                passwordManager.displayPasswords();
                break;
            case 3:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}

