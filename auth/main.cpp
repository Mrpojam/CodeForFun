#include<bits/stdc++.h>

using namespace std; 

#include "libraries/auth.h"

int main () {
    while (true) {
        system("clear");
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "1-create new user\n";
        cout << "2-login with user\n";
        int command = 0;
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cin >> command;
        cout << "username : ";
        string username;
        cin >> username;
        string password;
        cout << "password : ";
        cin >> password;
        if (command == 1) {
            pair<bool, string> user = create_new_user(username, password);
            cout << user.second << endl;
        }
        else {
            pair<bool, string> log = login(username, password);
            cout << log.second << endl;  
        }
        cout << "Enter smth to continue : ";
        char c;
        cin >> c;
    }
    return 0;
}

