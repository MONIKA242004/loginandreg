#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
unordered_map<string, string> userDatabase;
void registerUser(const string &username, const string &password) {
    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "Username already exists. Please try again." << endl;
        return;
    }
    userDatabase[username] = password;
    cout << "Registration successful!" << endl;
}
void loginUser(const string &username, const string &password) {
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

int main() {
    string usernames[] = {"user1", "user2", "user3"};
    string passwords[] = {"pass1", "pass2", "pass3"};
    for (int i = 0; i < 3; i++) {
        registerUser(usernames[i], passwords[i]);
    }
    string loginUsernames[] = {"user1", "user2", "user4"};
    string loginPasswords[] = {"pass1", "wrongpass", "pass4"};
    for (int i = 0; i < 3; i++) {
        cout << "\nAttempting to login with Username: " << loginUsernames[i]
             << " and Password: " << loginPasswords[i] << endl;
        loginUser(loginUsernames[i], loginPasswords[i]);
    }

    return 0;
}
