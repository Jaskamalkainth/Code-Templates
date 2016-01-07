/******
 *
 *
 *  cnt_factor(n) returns the number of divisors of n
 *
 *  
 */

const int maxN = 1e6+7;
int  pp[maxN+1];
vector <int> prime;
inline void pre_sieve()
{
    // there are 1007 primes < 8000 
    // there are 78499   primes < 1e6+7
    for(ll i = 2; i < 1001; i++ )
        if(!pp[i] )
            for(ll j = i*i; j < maxN; j += i)
                pp[j] = 1;

    for(int i =2; i< maxN; i++)
        if(pp[i] == 0)
            prime.push_back(i);
}

int nprime;

ll cnt_factor(ll n )
{
	ll ans = 1ll ;
	int i = 0;
	while(prime[i] * prime[i] < n  && i < nprime )
	{
		int wt = 0;
		while(n % prime[i]== 0 )
		{
			wt++;
			n /= prime[i];
		}
		ans *= (wt+1);
		i++;
	}
	if( n > 1 )
		ans *= 2;

	return ans;
}
