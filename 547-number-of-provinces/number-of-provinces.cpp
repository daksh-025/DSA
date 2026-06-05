class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> adj[n];

        // Convert matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;
    }
};