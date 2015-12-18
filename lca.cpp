/*
 * O<nlogn,logn>
 */
const int MAXN = 1e6+7; 
const int MAXLOG = 20; 

int par[MAXN][MAXLOG]; // initially all -1

vi adj[MAXN];
int d[MAXN];

void dfs(int v,int p = -1){
    par[v][0] = p;
    if(p + 1)
        d[v] = d[p] + 1;
    for(int i = 1;i < MAXLOG;i ++)
        if(par[v][i-1] + 1)
            par[v][i] = par[par[v][i-1]][i-1];
    for(auto u : adj[v])
        if(p - u)
            dfs(u,v);
}

int lca(int v,int u){
    if(d[v] < d[u])
        swap(v,u);
    for(int i = MAXLOG - 1;i >= 0;i --)
        if(par[v][i] + 1 and d[par[v][i]] >= d[u])
            v = par[v][i];
    if(v == u)
        return v;
    for(int i = MAXLOG - 1;i >= 0;i --)
        if(par[v][i] - par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}

int dist(int u , int  v)
{
    int l = lca( u , v);
    return ( d[u] + d[v] - 2 * d[l] );
}


