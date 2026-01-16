#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // stores climbs

        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff > 0) {
                minHeap.push(diff);

                // If we used more climbs than ladders, use bricks for the smallest climb
                if (minHeap.size() > ladders) {
                    bricks -= minHeap.top();
                    minHeap.pop();

                    // If we run out of bricks, we can't go further
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }

        // If we never run out of bricks, we reach the last building
        return heights.size() - 1;
    }
};
