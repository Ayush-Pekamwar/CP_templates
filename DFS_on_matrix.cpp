void dfs(vector<vector<char>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || i<0 || j>=m || j<0) return;
        if(grid[i][j]=='0') return;

        grid[i][j]='0';

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
}
