class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int a = 0;
                    computeArea(grid, i, j, a);
                    area = max(area, a);
                }
            }
        }
        return area;
    }
private:
    void computeArea(vector<vector<int>>& grid, int i, int j, int& a) {
        int m = grid.size(), n = grid[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j]) {
            a++;
            grid[i][j] = 0;            
            computeArea(grid, i - 1, j, a);
            computeArea(grid, i + 1, j, a);
            computeArea(grid, i, j - 1, a);
            computeArea(grid, i, j + 1, a);
        }
    }
};