class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n= profits.size();
        for(int i=0;i<n;i++){
            pq.push({capital[i],profits[i]});         
        }

        priority_queue<int> maxProfit;
        for(int i=0;i<k;i++){

            while(!pq.empty() && pq.top().first <= w){
                maxProfit.push(pq.top().second);
                pq.pop();
            }
            if (maxProfit.empty()) break; 

            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};