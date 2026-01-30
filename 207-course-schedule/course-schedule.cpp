class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);


        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }


        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return topo;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for (auto &arr : prerequisites) {
            adj[arr[1]].push_back(arr[0]); 
        }

        vector<int> topo = topoSort(numCourses, adj);

        return topo.size() == numCourses;
    }
};
