
const int maxn = 1e5+7;
inline vector<int> toposort(int n , vector<int> G[maxn] , int indegree[maxn])
{
	vi ans;
	queue<int> qq;
	for(int i = 1; i <= n; i++)
		if(indegree[i] == 0)
			qq.push(i);
	int cnt = 0;
	while(!qq.empty())
	{
		int u = qq.front();
		qq.pop();
		ans.push_back(u);
		for(auto &v: G[u])
		{
			indegree[v]--;
			if(indegree[v] == 0)
				qq.push(v);
		}
		cnt++;
	}
	if(cnt != n)
	{
		cout << "CYCLE\n";  
	}
	return ans;
}
/*

   int n , m; 
   cin >> n >> m;
   int indegree[maxn];
   vi G[maxn];

   for(int i = 1; i <= n; i++)
   {
   int u ,v; cin >> u >> v;
   G[u].pb(v);
   indegree[v]++;
   }
   vi ans = toposort(n, G, indegree);
   cout << ans << "\n";

*/
