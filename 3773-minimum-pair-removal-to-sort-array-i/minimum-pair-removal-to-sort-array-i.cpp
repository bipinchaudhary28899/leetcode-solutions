class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int n = nums.size();
            int minSum = INT_MAX;
            int idx = -1;

            // Find the adjacent pair with minimum sum (leftmost if tie)
            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // Merge the pair at idx and idx+1
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }
};
