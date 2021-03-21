#include "validator.h"
#include "hash_lib.h"

pair<bool, string> login (string username, string password) {
    long long hash = incrypt(password);
    long long us = incrypt(username);
    pair<bool, string> message;
    string filename = to_string(us);
    ifstream pas("DATA/"+filename);
    long long file;
    pas >> file;
    if (hash == file)
        message = {true, "You are logged in."};
    else 
        message = {false, "Password or Username is not right"};
    return message;
}

bool exists(string username) {
    long long hash = incrypt(username);
    ifstream pas("DATA/"+hash);
    long long file;
    pas >> file;
    if (file != 0)
        return true;
    return false;
}

pair<bool, string> create_new_user (string username, string password) {
    if (exists(username)) {
        return {false, "User exists!"};
    }
    pair<bool, string> message = is_valid(password);
    if (!message.first)
        return message;
    long long hash = incrypt(password);
    long long us = incrypt(username);

    string filename = to_string(us);

    ofstream pas("DATA/"+filename);
    pas << hash;
    pas.close();
    return message;
}

