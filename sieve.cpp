const int maxN = 1e6+7;
int  pp[maxN+1];
vector <int> prime;
inline void pre_sieve()
{
    // there are 1007 primes < 8000 
    // there are 78499   primes < 1e6+7
    for(ll i = 2; i < maxN; i++ )
        if( pp[i] == 0 )
            for(ll j = i*i; j < maxN; j += i)
                pp[j] = 1;

    for(int i =2; i< maxN; i++)
        if(pp[i] == 0)
            prime.push_back(i);
}

