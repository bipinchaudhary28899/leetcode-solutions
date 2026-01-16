class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // Add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Collect all possible horizontal distances
        unordered_set<int> hDist;
        int H = hFences.size();
        for (int i = 0; i < H; i++) {
            for (int j = i + 1; j < H; j++) {
                hDist.insert(hFences[j] - hFences[i]);
            }
        }

        // Collect all possible vertical distances
        unordered_set<int> vDist;
        int V = vFences.size();
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                vDist.insert(vFences[j] - vFences[i]);
            }
        }

        long long best = -1;

        // Find the largest L such that L in both sets
        for (int d : hDist) {
            if (vDist.count(d)) {
                best = max(best, (long long)d);
            }
        }

        if (best == -1) return -1;

        return (best * best) % MOD;
    }
};
