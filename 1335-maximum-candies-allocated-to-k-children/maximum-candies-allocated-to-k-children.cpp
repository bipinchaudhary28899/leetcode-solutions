class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long children = 0;

            for (int c : candies) {
                children += c / mid;
            }

            if (children >= k) {
                ans = mid;        // valid
                left = mid + 1;
            } else {
                right = mid - 1;  // invalid
            }
        }
        return ans;
    }
};
