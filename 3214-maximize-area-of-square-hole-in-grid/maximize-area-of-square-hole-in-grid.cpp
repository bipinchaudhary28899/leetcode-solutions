class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort both arrays
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Find max consecutive horizontal bars
        int maxH = 1, currH = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                currH++;
            } else {
                currH = 1;
            }
            maxH = max(maxH, currH);
        }

        // Find max consecutive vertical bars
        int maxV = 1, currV = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                currV++;
            } else {
                currV = 1;
            }
            maxV = max(maxV, currV);
        }

        // Convert bars to gap size (cells)
        int maxHGap = maxH + 1;
        int maxVGap = maxV + 1;

        int squareSide = min(maxHGap, maxVGap);
        return squareSide * squareSide;
    }
};
