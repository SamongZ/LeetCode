/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> prime(n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i)
                    prime[j] = 0;
            }
        }
        return count(prime.begin(), prime.end(), 1);
    }
};
