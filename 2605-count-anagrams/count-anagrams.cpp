#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Modular exponentiation: (base^exp) % mod
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countAnagrams(string s) {
        // Step 1: Calculate max word length to resize factorial array
        int maxLen = 0;
        stringstream ss_len(s);
        string tempWord;
        while (ss_len >> tempWord) {
            maxLen = max(maxLen, (int)tempWord.size());
        }

        // Step 2: Precompute factorials up to maxLen
        vector<long long> fact(maxLen + 1, 1);
        for (int i = 2; i <= maxLen; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long long ans = 1;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }

            long long count = fact[word.size()];
            for (int f : freq) {
                if (f > 1) {
                    count = (count * modPow(fact[f], MOD - 2, MOD)) % MOD;
                }
            }

            ans = (ans * count) % MOD;
        }

        return static_cast<int>(ans);
    }
};
