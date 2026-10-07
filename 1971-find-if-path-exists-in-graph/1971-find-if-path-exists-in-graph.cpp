class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination){
            return true;
        }

        int p = edges.size();

        vector<bool> visit(n, false);
        vector<vector<int>> adj(n);

        queue<int> q;

        // Create adjacency list
        for(int j = 0; j < p; j++) {
            int u = edges[j][0];
            int v = edges[j][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visit[source] = true;
        q.push(source);

        while(!q.empty()){

            int temp = q.front();
            q.pop();

            if(temp == destination)
                return true;

            for(int i = 0; i < adj[temp].size(); i++){;

                if(visit[adj[temp][i]] == false){
                    visit[adj[temp][i]] = true;
                    q.push(adj[temp][i]);
                }
            }
        }

        return false;
    }
};