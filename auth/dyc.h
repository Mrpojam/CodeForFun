
bool is_valid (string username, string password) {
    long long pw[100000], hash = 0, us = 0;
    int mod = 1e9+9;
    int p = 31;
            
    pw[0] = 1;
    for (int i = 1; i <= 10000; i++)
        pw[i] = (pw[i-1] * p) % mod;

    for (int i = 0; i < password.size(); i++)
        hash = (hash + (password[i] - 'a' + 1) * pw[i]) % mod;

    for (int i = 0; i < username.size(); i++)
        us = (us + (username[i] - 'a' + 1) * pw[i]) % mod;

    string filename = to_string(us);
    ifstream pas(filename);
    long long file;
    pas >> file;
    return file == hash;   
}