long long incrypt (string pattern) {
    long long pw[100000], hash = 0, us = 0;
    int mod = 1e9+9;
    int p = 31;
            
    pw[0] = 1;
    for (int i = 1; i <= 10000; i++)
        pw[i] = (pw[i-1] * p) % mod;

    for (int i = 0; i < pattern.size(); i++)
        hash = (hash + (pattern[i] - 'a' + 1) * pw[i]) % mod;
    return hash;
}

