/*
Problem: LeetCode 286 - Walls and Gates



Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. In the worst case, we may need to visit all the rooms.

Space Complexity:
The space complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. This is the space used for the queue to store the coordinates of the gates.
*/

class Solution {
  public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        if (rooms.empty()) {
            return;
        }

        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> gates;  // Queue to store the coordinates of the gates

        // Enqueue the coordinates of the gates
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    gates.push({i, j});
                }
            }
        }

        // Perform a BFS traversal
        while (!gates.empty()) {
            int size = gates.size();

            for (int i = 0; i < size; ++i) {
                int row = gates.front().first;
                int col = gates.front().second;
                gates.pop();
                // Check neighboring rooms (up, down, left, right)
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for (const auto &dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && rooms[newRow][newCol] == INT32_MAX) {
                        // Mark the neighboring room with the distance to the gate and enqueue its coordinates
                        rooms[newRow][newCol] = rooms[row][col] + 1;
                        gates.push({newRow, newCol});
                    }
                }
            }
        }
    }
};