/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1
Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
]
Output: 1

Example 2
Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
]
Output: 3
*/

#include <stdio.h>

void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    if (r < 0 || c < 0 || r >= gridSize || c >= gridColSize[r] || grid[r][c] == '0') return;
    grid[r][c] = '0';
    
    dfs(grid, gridSize, gridColSize, r - 1, c);
    dfs(grid, gridSize, gridColSize, r + 1, c);
    dfs(grid, gridSize, gridColSize, r, c - 1);
    dfs(grid, gridSize, gridColSize, r, c + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) {
        return 0;
    }
    
    int num_islands = 0;
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                num_islands++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    
    return num_islands;
}