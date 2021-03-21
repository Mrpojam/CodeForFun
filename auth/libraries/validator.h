pair<bool, string> is_valid (string password) {
    pair<bool, string> message;
    int _size = password.size();
    if (_size < 6 || _size >= 20) {
        message = {false, "Password Size must be longer than 6 and shorter than 20"};
    }
    bool is_integer = false;
    bool is_char = false;
    for (char c : password) {
        if (c >= '0' && c <= '9')
            is_integer = true;
        else 
            is_char = true;
    }
    if (!is_integer) message = {false, "password must contain atleast one integer"};
    if (!is_char) message = {false, "password must contain atleast one char"};
    if (is_char && is_integer) message = {true, "password is valid"};
    return message;
}