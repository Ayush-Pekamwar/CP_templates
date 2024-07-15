// DFS on Matrix/Grid
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

// DFS on Tree to get parent array
void dfsToGetPar(vector<int>* g, vector<int>& par, int u, int p = -1) {
    par[u] = p;
    for (auto child : g[u]) {
        if (child == p) {
            continue;
        }
        dfsToGetPar(g, par, child, u);
    }
}


// DFS on Tree to fill Height and Depth of Node array
void dfs(vector<int>* g, int* par, int u) {  
    for (auto child : g[u]) {
        if (child == par[u]) continue;

        depth[child] = depth[par[child]] + 1;
        dfs(g, par, child);

        height[u] = max(height[u], height[child] + 1);
    }
}

