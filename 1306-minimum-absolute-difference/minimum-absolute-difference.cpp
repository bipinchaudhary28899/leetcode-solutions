class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int globalMin = INT_MAX;

        
        for (int i = 1; i < n; i++) {
            globalMin = min(globalMin, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == globalMin) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
