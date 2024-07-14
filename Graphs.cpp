// DFS start
const int N = 1e4;
vector<int>graph[N];
bool vis[N];

void dfs(int v) {
    // take action on vertex(v) just after entering the vertex
    vis[v] = 1;

    for (auto c : graph[v]) {
        // take action on child(c) of vertex(v) before entering child node
        if (vis[c]) continue;
        dfs(c);

        // take action on child(c) of vertex(v) after exiting the child node
    }

    // take action on vertex(v) before exiting the vertex
}
// DFS end


// optmised DSU 
const int N = 2e5 + 10;
int par[N];
int sz[N];

void make(int u) {
    par[u] = u;
    sz[u] = 1;
}

int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (sz[b] > sz[a]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
// DSU end

