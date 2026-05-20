/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.

Example 1
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Pair;

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {

    int m = matSize;
    int n = matColSize[0];

    *returnSize = m;

    *returnColumnSizes = (int*)malloc(sizeof(int) * m);

    int** dist = (int**)malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        dist[i] = (int*)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }

    Pair* queue = (Pair*)malloc(sizeof(Pair) * m * n);
    int front = 0, rear = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                queue[rear++] = (Pair){i, j};
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (front < rear) {
        Pair cur = queue[front++];

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                dist[nx][ny] == -1) {

                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                queue[rear++] = (Pair){nx, ny};
            }
        }
    }

    free(queue);

    return dist;
}