class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            int move = nums[i];
            int newIndex = (i + move) % n;

            if (newIndex < 0) newIndex += n;

            v[i] = nums[newIndex];
        }

        return v;
    }
};
