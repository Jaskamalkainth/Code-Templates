const int maxn = 1e5+7;
vector<int> G[maxn];
int n , m;
int vis[maxn];
stack<int> st;
void dfs(int u)
{
	vis[u] = 1;
	for(auto &v: G[u])
		if(!vis[v])
			dfs(v);
	st.push(u);
}
vector<int> toposort()
{
	for(int i = 1; i <= n; i++)
		if(!vis[i])
			dfs(i);
	vector<int> ans;
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
/*
   cin >> n >> m;
   for(int i = 1; i <= m; i++)
   {
   int u ,v; cin >> u >> v;
   G[u].pb(v);
   }
   vi ans = toposort();

*/
