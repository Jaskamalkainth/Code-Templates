const int maxn = 7e4+7;
const int nine_len = 1e9+1;
int P0[maxn], P1[maxn];
ll prime[2],mod[2];


pair<int,int> HashF[maxn], HashR[maxn];


inline int check_prime(ll n)
{
	int flag = 0;
	for(int i = 2; i * i < n; i++)
		if(n % i == 0)
			flag = 1;
	if(flag)
		return 0;
	else
		return 1;
}
inline void RollingHash_double()
{
	prime[0] = 31;
	prime[1] = 37;
	ll rand_mod1 = nine_len + rand() % nine_len;
	ll rand_mod2 = nine_len + rand() % nine_len;
	while(!check_prime(rand_mod1))
	{
		rand_mod1++;  
	}
	while(!check_prime(rand_mod2))
	{
		rand_mod2++;  
	}
	while(rand_mod1 == rand_mod2)
	{
		rand_mod1++;
		while(!check_prime(rand_mod1))
		{
			rand_mod1++;  
		}
	}
	mod[0] = rand_mod1;
	mod[1] = rand_mod2;
	P0[0] = P1[0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		P0[i] = (1ll * P0[i-1] * prime[0]) % mod[0];
		P1[i] = (1ll * P1[i-1] * prime[1]) % mod[1];
	}
}
inline void Construct(string s)
{
	int len = s.length();
	HashF[0] = HashR[len+1] = {0,0};
	
	for(int i = 1; i <= len; i++)
	{
		HashF[i].first = (1ll * HashF[i-1].first * prime[0] + s[i-1] ) % mod[0];
		HashF[i].second = (1ll * HashF[i-1].second * prime[1] + s[i-1] ) % mod[1];

		HashR[len-i+1].first = (1ll * HashR[len-i+2].first * prime[0] + s[len-i] ) % mod[0];
		HashR[len-i+1].second = (1ll * HashR[len-i+2].second * prime[1] + s[len-i]) % mod[1];
	}
}
inline pair<int,int> getHashValue(string s)
{
	Construct(s);
	int len  = s.length();
	return {HashF[len].first,HashF[len].second};
}
inline pair<int,int> GetForwardHash(int l ,int r , int len)
{
	if(l == 1)
		return HashF[r];
	pair<int,int> hashp;

	hashp.first = (HashF[r].first - 1ll * HashF[l-1].first * P0[r-l+1] ) % mod[0];
	if(hashp.first < 0)
		hashp.first += mod[0];

	hashp.second = (HashF[r].second- 1ll * HashF[l-1].second * P1[r-l+1] ) % mod[1];
	if(hashp.second < 0)
		hashp.second += mod[1];
	return hashp;
}

inline pair<int,int> GetReverseHash(int l ,int r , int len)
{
	if(r == len)
		return HashR[l];
	pair<int,int> hashp;
	hashp.first= (HashR[l].first - 1ll * HashR[r+1].first* P0[r-l+1]) % mod[0];
	if(hashp.first< 0)
		hashp.first+= mod[0];
	hashp.second= (HashR[l].second- 1ll * HashR[r+1].second * P1[r-l+1] ) % mod[1];
	if(hashp.second < 0)
		hashp.second += mod[1];
	return hashp;
}

bool isPalin(int l , int r, int len)
{
	if( r < l ) return true;
	return (GetForwardHash(l,r,len) == GetReverseHash(l,r,len));
}


/*
 * string s; cin >> s;
	int len = s.length();

	RollingHash_double();
	Construct(s);
	*/






