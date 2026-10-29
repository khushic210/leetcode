
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        queue<vector<int>> q;
        q.push({0, 0, 1});

        vector<vector<int>> direction = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},  {0,1},
            {1,-1},  {1,0},  {1,1}
        };

        grid[0][0] = 1;

        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();

            int r = temp[0];
            int c = temp[1];
            int l = temp[2];

            if (r == n-1 && c == n-1) {
                return l;
            }

            for (auto i : direction) {
                int nr = r + i[0];
                int nc = c + i[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    q.push({nr, nc, l+1});
                    grid[nr][nc] = 1;
                }
            }
        }

        return -1;
    }
};

