class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> freq;
        for (auto &word : words) {
            freq[word]++;
        }
        
        auto cmp = [&](pair<string,int> &a, pair<string,int> &b) {
            if (a.second == b.second)
                return a.first < b.first; 
            return a.second > b.second;
        };
        
        priority_queue<pair<string,int>, 
                       vector<pair<string,int>>, 
                       decltype(cmp)> pq(cmp);
        
        for (auto &p : freq) {
            pq.push(p);
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }
        
        return result;
    }
};