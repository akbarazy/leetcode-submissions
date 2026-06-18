/*
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: 
The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3
Input: grid = [[0,2]]
Output: 0
Explanation: 
Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh_count = 0;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh_count++;
            }
        }
    }
    
    if (fresh_count == 0) return 0;
    
    int minutes = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty() && fresh_count > 0) {
        int q_size = q.size();
        
        for (int i = 0; i < q_size; ++i) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh_count--;
                    q.push({nr, nc});
                }
            }
        }

        minutes++;
    }
    
    return fresh_count == 0 ? minutes : -1;
}