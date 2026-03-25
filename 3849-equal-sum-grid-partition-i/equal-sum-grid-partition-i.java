class Solution {
    public boolean canPartitionGrid(int[][] grid) {
    int m = grid.length;
    int n = grid[0].length;

    long totalSum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            totalSum += grid[i][j]; // long sum
        }
    }

    long sumTop = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            sumTop += grid[i][j];
        }
        if (sumTop * 2 == totalSum) {
            return true;
        }
    }

    long[] colSum = new long[n];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            colSum[j] += grid[i][j];
        }
    }

    long sumLeft = 0;
    for (int j = 0; j < n - 1; j++) {
        sumLeft += colSum[j];
        if (sumLeft * 2 == totalSum) {
            return true;
        }
    }

    return false;
}
}
