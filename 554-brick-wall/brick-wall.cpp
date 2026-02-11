class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int,int> freq;
    int maxEdges = 0;

    for (auto &row : wall) {
        long long sum = 0;
        for (int i = 0; i < row.size() - 1; i++) {
            sum += row[i];
            maxEdges = max(maxEdges, ++freq[sum]);
        }
    }

    return wall.size() - maxEdges;
}

};