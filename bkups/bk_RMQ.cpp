#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <list>
#include <map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
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
#define sor(a)             sort(all(a));
#define pr(n)              printf("%d ",n)
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

inline int next(){ int x; scanf("%d",&x); return x; }

const int MAX=1e6+7;
const int LMAX=20;
ll A[MAX];
//const int LMAX=(int)ceil(log(MAX)) = 14 ;
ll M[MAX][LMAX];
void process(int n)
{
    for(int i=0;i<n;i++)
        M[i][0]=i;
    for(int j=1; 1<<j <= n; j++)
        for(int i=0;i+(1<<j) -1 < n;i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int RMQ(int i,int j)
{
    int k=(log2(j-i+1));
    if (A[M[i][k]] <= A[M[j-(1 << k)+1][k]])
        return(M[i][k]);
    else
        return(M[j - (1 << k)+1][k]);
} 
//process(n); //nlogn pre processing
// A[RMQ(x,y)]  min in x and y
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n = next(); 
    for ( int i = 0;i < n; i++ )
    {
        A[i] = next();
    }

    process(n);

    int q = next(); 

    while(q--)
    {

        int i = next();
        int j = next();

        i--; j--;

        printf("%lld\n", A[RMQ(i,j)]);
    }


    return 0;
}


