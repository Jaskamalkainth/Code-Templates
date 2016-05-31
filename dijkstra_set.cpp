const int maxN = 5e4+7;
vector<pair<int,int> > G[maxN];
int dist[maxN];
int n , m , s;
void printGraph()
{
	for(int i = 1;i <= n; i++)
		{
			printf("ADJ of %d = ",i);
			for(auto x: G[i])
				printf("(%d,%d) ",x.ff,x.ss);  
			cout << "\n";
		}
}
void dijkstra(int source)
{
	for(int i = 1; i <= n; i++)
		dist[i] = 9999;
	dist[source] = 0;
	set<pair<int,int> > s;
	s.insert(mp(0,source));
	while(!s.empty())
	{
		pair<int,int> top = *s.begin();
		s.erase(s.begin());
		int d = top.first;
		int u = top.second;
		for(auto &x: G[u])
		{
			int v = x.first;
			int cost = x.second;
			if(dist[v] >  dist[u] + cost)
			//make sure dist[u] + cost does not overflow so dont use mx_int
			{
				if(dist[v] != 9999)
					s.erase(s.find(pii(dist[v],v)));
				dist[v] = dist[u] + cost;
				s.insert(mp(dist[v],v));
			}
		}
	}
}

