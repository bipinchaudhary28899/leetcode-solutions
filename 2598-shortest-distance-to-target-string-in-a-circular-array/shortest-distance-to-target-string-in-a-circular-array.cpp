class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    int minDist = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (words[i] == target) {
            int diff = abs(i - startIndex);
            int dist = min(diff, n - diff);  
            minDist = min(minDist, dist);
        }
    }

    return (minDist == INT_MAX) ? -1 : minDist;
}
};