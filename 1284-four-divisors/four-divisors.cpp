class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int getSumIfFourDivisors(int n) {
        // Case 1: p^3
        for (int p = 2; p * p * p <= n; p++) {
            if (isPrime(p) && p * p * p == n) {
                return 1 + p + p * p + n;
            }
        }

        // Case 2: p * q
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;
                if (i != j && isPrime(i) && isPrime(j)) {
                    return 1 + i + j + n;
                }
                return 0;
            }
        }
        return 0;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {   // n is int (element of vector)
            total += getSumIfFourDivisors(n);
        }
        return total;
    }
};
