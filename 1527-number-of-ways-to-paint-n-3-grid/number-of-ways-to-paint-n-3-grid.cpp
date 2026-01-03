class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;

        long long a = 6; // Type A: ABC
        long long b = 6; // Type B: ABA

        for (int i = 1; i < n; i++) {
            long long newA = (2 * a + 2 * b) % MOD;
            long long newB = (2 * a + 3 * b) % MOD;
            a = newA;
            b = newB;
        }

        return (a + b) % MOD;
    }
};