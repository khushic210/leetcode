
class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int cr = curr.first;
            int cc = curr.second;

            for (int k = 0; k < 4; k++) {
                int nr = cr + dr[k];
                int nc = cc + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' &&
                    visited[nr][nc] == 0) {

                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();

        if (r == 0) return 0;

        int c = grid[0].size();

        vector<vector<int>> visited(r, vector<int>(c, 0));

        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    count++;
                    bfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};

