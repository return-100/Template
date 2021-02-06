int find(int u)
{
    return parent[u] = (parent[u] == u ? u : find(parent[u]));
}

bool merge(int u, int v)
{
    int pu = find(u);
    int pv = find(v);

    if (pu == pv) {
        return false;
    }
    else if (sz[pu] > sz[pv]) {
        sz[pu] += sz[pv], parent[pv] = pu;
    }
    else {
        sz[pv] += sz[pu], parent[pu] = pv;
    }

    return true;
}
