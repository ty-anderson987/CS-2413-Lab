#include <stdio.h>





void dfs(char** grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        return;
    
    grid[i][j] = '0';
    
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i, j - 1, m, n);
    dfs(grid, i, j + 1, m, n);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize == 0)
        return 0;

    int count = 0;
    int m = gridSize;
    int n = gridColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j, m, n);
            }
        }
    }

    return count;
}
