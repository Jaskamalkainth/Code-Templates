
const int maxN = 1e4+6;
vector<pii >G[maxN];
vector<pii> edge;
vector<int> par(maxN,-1);
vector<int> dist(maxN,1e7);
int  n  , m;
int ans = 0;
void prim( int source )
{
	set<pair<int,int> > s;
	for(int i = 1; i <= n; i++)
	{
		if(i == source)
			s.insert(pii(0,i));
		else
			s.insert(pii(dist[i],i));
	}
	dist[source] = 0;
	while(!s.empty())
	{
		pii top = *s.begin();
		s.erase(s.begin());
		int u = top.ss;
		int d = top.ff;
		ans += d;
		if( u != source)
			edge.pb(pii(par[u],u));
		for(auto &x: G[u])
		{
			int v = x.ff;
			int cost = x.ss;
			if(s.find(pii(dist[v],v)) != s.end())
			{
				if(dist[v] > cost)
				{
					s.erase(s.find(pii(dist[v],v)));
					dist[v] = cost;
					s.insert(pii(dist[v],v));
					par[v] = u;
				}
			}
		}
	}
}
/*
   prim(s);
   debug(edge.size());
   for(auto e: edge)
   		printf("(%d -> %d ) ",e.ff,e.ss);

		ans = sum of edge weights of MST
   */
