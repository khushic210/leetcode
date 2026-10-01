class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = edges.size();
        int m = vals.size();

        vector<vector<int>> result(m);

        for(int j = 0; j < n; j++) {
            int u = edges[j][0];
            int v = edges[j][1];

            result[u].push_back(vals[v]);
            result[v].push_back(vals[u]);
        }

        int maxi = INT_MIN;

        for(int i = 0; i < m; i++) {
            sort(result[i].begin(), result[i].end(), greater<int>());

            int s = vals[i];

            for(int p = 0; p < min((int)result[i].size(), k); p++) {
                if(result[i][p] < 0)
                    break;

                s += result[i][p];
            }

            maxi = max(maxi, s);
        }

        return maxi;
    }
};