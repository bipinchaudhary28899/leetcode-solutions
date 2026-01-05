class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int negativeCount = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = matrix[i][j];
                sum += abs(val);
                minAbs = min(minAbs, abs(val));
                if (val < 0) negativeCount++;
            }
        }

        if (negativeCount % 2 != 0) {
            sum -= 2LL * minAbs;
        }

        return sum;
    }
};
