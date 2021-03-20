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
        if (command == 1)
            create_new_user(username, password);
        else {
            bool lg = is_valid(username, password);
            if (lg) cout << "TRUE";
            else cout << "FALSE";
            cout << endl;
            int c;
            cin >> c;
        }
    }
    return 0;
}

