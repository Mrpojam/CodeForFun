#include<bits/stdc++.h>

using namespace std; 

#include "inc.h"
#include "dyc.h"

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
            bool lg = is_valid(username, password);
            if (lg) cout << "You are logged in!";
            else cout << "Username or password did not match!";
            cout << endl;
        }
        cout << "Enter smth to continue : ";
        char c;
        cin >> c;
    }
    return 0;
}

