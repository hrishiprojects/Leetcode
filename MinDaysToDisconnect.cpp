class Solution {
public:
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j])
            return;
        visited[i][j] = true;
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }

    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j); // Explore the island
                }
            }
        }
        return count;
    }
    

    int minDays(vector<vector<int>>& grid) {
        if (countIslands(grid) != 1) return 0;
        
        int m = grid.size(), n = grid[0].size();

        // Step 2: Try removing one land cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Remove the land cell
                    if (countIslands(grid) != 1) return 1; // Check if disconnected
                    grid[i][j] = 1; // Restore the land cell
                }
            }
        }

        // Step 3: Try removing two land cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Remove the first land cell
                    for (int x = 0; x < m; ++x) {
                        for (int y = 0; y < n; ++y) {
                            if (grid[x][y] == 1) {
                                grid[x][y] = 0; // Remove the second land cell
                                if (countIslands(grid) != 1) return 2; // Check if disconnected
                                grid[x][y] = 1; // Restore the second land cell
                            }
                        }
                    }
                    grid[i][j] = 1; // Restore the first land cell
                }
            }
        }

        return 2;
    }
};