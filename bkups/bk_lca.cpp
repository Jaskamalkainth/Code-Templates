/*
 *
 *    J1K7_7
 * 
 */
#include<bits/stdc++.h> 
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
typedef long double        ld;
typedef pair<int,int>      pii;
typedef pair<ll,ll>        pll;
typedef vector<int>        vi;
typedef vector<long long>  vll;
#define l(x) 		       (x << 1) + 1
#define r(x) 		       (x << 1) + 2
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define pr(n)              printf("%d",n)
#define s(n)               scanf("%d",&n)
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))
#define snuke(c,itr)       for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
const int mod=1e9+7;

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);

inline bool ispow2(int x){return (x!=0 && (x&(x-1))==0);} //0 or 1

int msb(unsigned x){ union { double a; int b[2]; }; a = x; return (b[1] >> 20) - 1023; }

template<class T>
inline void cinarr(T a, int n){ for (int i=0;i<n;++i) cin >> a[i];}

inline ll powmod(ll a,ll b) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }


const int MAXN = 1e5+7; 
const int MAXLOG = 20; 

int par[MAXN][MAXLOG]; // initially all -1

vi adj[MAXN];
int h[MAXN];

void dfs(int v,int p = -1){
    par[v][0] = p;
    if(p + 1)
        h[v] = h[p] + 1;
    for(int i = 1;i < MAXLOG;i ++)
        if(par[v][i-1] + 1)
            par[v][i] = par[par[v][i-1]][i-1];
    for(auto u : adj[v])if(p - u)
        dfs(u,v);
}

int LCA(int v,int u){
    if(h[v  ] < h[u])
        swap(v,u);
    for(int i = MAXLOG - 1;i >= 0;i --)
        if(par[v][i] + 1 and h[par[v][i]] >= h[u])
            v = par[v][i];
    // now h[v] = h[u]
    if(v == u)
        return v;
    for(int i = MAXLOG - 1;i >= 0;i --)
        if(par[v][i] - par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);



    int t = nextint();

    for(int k = 0; k < t ; k++)
    {

        // clear all containers

        int n = nextint() ; 
        for(int i = 0; i < n ; i++)
        {
            int m = nextint();
            while(m--)
            {
                int x = nextint();
                x--;
                adj[i].pb(x);
                adj[x].pb(i);
            }
        }

        int q = nextint();

        dfs(0);

        cout << "Case " << k+1 <<":" << "\n";
        while(q--)
        {
            int u = nextint();
            int v = nextint();

            cout << LCA(u-1,v-1) + 1 << "\n";
        }


        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
        m0(par);
        m0(h);

    }
    return 0;
}
