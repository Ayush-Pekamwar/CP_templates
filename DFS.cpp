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
