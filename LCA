
vector <int> vec[maxn];
int n, depth[maxn], table[maxn][17], parent[maxn];

void dfs(int u)
{
    for (int i = 0; i < vec[u].size(); ++i)
    {
        if (vec[u][i] != parent[u])
        {
            parent[vec[u][i]] = u;
            depth[vec[u][i]] = depth[u] + 1;
            dfs(vec[u][i]);
        }
    }
}

void preprocess()
{
    memset(table, -1, sizeof(table));
    
    for (int i = 1; i <= n; ++i)
        table[i][0] = parent[i];
    
    for (int j = 1; (1 << j) < n; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (table[i][j - 1] != -1)
                table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    
    int var = 1, ret;
    
    while ((1 << var) <= depth[u])
        ++var;
    
    --var;
    
    for (int i = var; i >= 0; --i)
    {
        if (depth[u] - (1 << i) >= depth[v])
            u = table[u][i];
    }
    
    if (u == v)
        return u;
    
    for (int i = var; i >= 0; --i)
    {
        if(table[u][i] != -1 && table[u][i] != table[v][i])
            u = table[u][i], v = table[v][i];
    }
    
    return table[u][0];
}

int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}
