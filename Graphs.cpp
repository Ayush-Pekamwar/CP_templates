// This File contains standard template for DFS, BFS , Dijkstra , DSU

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



// BFS Algo
const int N = 1e5 + 10;
vector<int> g[N];
vector<int> level(N, 0), vis(N, 0);

void bfs(int source) {
    queue<int>q;
    q.push(source);
    vis[source] = 1;
    level[source] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto child : g[cur]) {
            if (vis[child])  continue;

            q.push(child);
            vis[child] = 1;
            level[child] = level[cur] + 1;
        }
    }
    // TC - O(N+M);
}
//BFS end



// Dijkstra Algo
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector <pair<int, int>> g[N];
// in graph I/P first element of pair be vertex to which g[i] is connected, second element is wt;

void dijkstra(int source) {
    vector<int> dis(N, INF);
    vector<int> vis(N, 0);

    set<pair<int, int>> st;
    // first element of set is distance from source , second element is the node no.
    st.insert({ 0,source });
    dis[source] = 0;
    vis[source] = 1;


    while (!st.empty()) {
        int v = st.begin()->second;
        int v_dis = st.begin()->first;
        st.erase(st.begin());

        if (vis[v])continue;
        vis[v] = 1;


        for (auto& child : g[v]) {
            int child_v = child.first;
            int wt = child.second;

            if (dis[child_v] > dis[v] + wt) {
                dis[child_v] = dis[v] + wt;
                st.insert({ dis[child_v],child_v });
            }
        }
    }
}




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


