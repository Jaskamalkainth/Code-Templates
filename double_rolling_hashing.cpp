const int maxn = 7e4+7;
struct mypair
{
	int l , r;  
};
mypair HashF[maxn], HashR[maxn];
int prime[2],mod[2];
int P0[maxn], P1[maxn];
inline void RollingHash_double()
{
	prime[0] = 31;
	prime[1] = 37;
	mod[0] = 999999937;
	mod[1] = 999999929;
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
		HashF[i].l = (1ll * HashF[i-1].l * prime[0] + s[i-1] ) % mod[0];
		HashF[i].r = (1ll * HashF[i-1].r * prime[1] + s[i-1] ) % mod[1];

		HashR[len-i+1].l = (1ll * HashR[len-i+2].l * prime[0] + s[len-i] ) % mod[0];
		HashR[len-i+1].r= (1ll * HashR[len-i+2].r * prime[1] + s[len-i]) % mod[1];
	}
}
inline pair<int,int> getHashValue(string s)
{
	Construct(s);
	int len  = s.length();
	return {HashF[len].l,HashF[len].r};
}
inline mypair GetForwardHash(int l ,int r , int len)
{
	if(l == 1)
		return HashF[r];
	pair<int,int> hashp;
	hashp.first = (HashF[r].l - 1ll * HashF[l-1].l * P0[r-l+1] ) % mod[0];
	if(hashp.first < 0)
		hashp.first += mod[0];

	hashp.second = (HashF[r].r- 1ll * HashF[l-1].r * P1[r-l+1] ) % mod[1];
	if(hashp.second < 0)
		hashp.second += mod[1];
	mypair FH;
	FH.l = hashp.first;
	FH.r = hashp.second;
	return FH;
}

inline mypair GetReverseHash(int l ,int r , int len)
{
	if(r == len)
		return HashR[l];
	pair<int,int> hashp;
	hashp.first= (HashR[l].l - 1ll * HashR[r+1].l* P0[r-l+1]) % mod[0];
	if(hashp.first< 0)
		hashp.first+= mod[0];
	hashp.second= (HashR[l].r- 1ll * HashR[r+1].r * P1[r-l+1] ) % mod[1];
	if(hashp.second < 0)
		hashp.second += mod[1];
	mypair FH;
	FH.l = hashp.first;
	FH.r = hashp.second;
	return FH;
}

bool isPalin(int l , int r, int len)
{
	if( r < l ) return true;
	mypair FH = GetForwardHash(l,r,len);
	mypair RH = GetReverseHash(l,r,len);
	if(FH.l == RH.l && FH.r == RH.r)
		return true;
	return false;
}


/*
 * string s; cin >> s;
	int len = s.length();

	RollingHash_double();
	Construct(s);
	*/






