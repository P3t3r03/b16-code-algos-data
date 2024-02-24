#include <iostream>
#include <string>


uint32_t hash(const std::string& str, const uint32_t m) {
    uint32_t char_hash = 0;
    uint32_t two_i = 1;
    uint32_t hash = 0;
    uint32_t two_i_mod = 256 % m;
    uint32_t hash_tot = 0;
    for(int i = 0; i < str.size(); i++) {
        two_i = two_i % m;
        char_hash = (uint32_t)str[i] % m;
        hash = (two_i * char_hash) % m;
        hash_tot = (hash_tot + hash) % m;
        two_i = two_i * two_i_mod;
    }
    return hash_tot;
}

int main() {
    std::string test = "THISISTHKDSKFJPCLKJD";
    uint32_t mod = 178;
    uint32_t hashed = hash(test, mod);
}

