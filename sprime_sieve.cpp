const int maxN = 1e6+7;
int  pp[maxN+1];
ll cnt[maxN+1]; // cnt[r] - cnt[l-1]  number of primes in [l,r]
vector <int> prime,sp;
inline void pre_sieve()
{
    sp.resize(maxN);
    // there are 1007  primes < 8000 
    // there are 78499 primes < 1e6+7
    for(ll i = 2; i < maxN; i++ )
        if( pp[i] == 0 )
        {
            sp[i] = i;
            for(ll j = i*i; j < maxN; j += i)
                if ( pp[j] == 0 )
                {
                    sp[j] = i;
                    pp[j] = 1;
                }
        }
    // sp[i] = i  iff i is prime
    for(int i =2; i< maxN; i++)
        if(pp[i] == 0)
            prime.push_back(i);

    for(int i = 2; i < maxN; i++)
        cnt[i] = cnt[i-1] + !(pp[i]);
    //sp[i] : smallest prime dividing i

    /*vi factorize_num;
      while(num > 1 )
      {
      factorize_num.pb(sp[num]);
      num = num/sp[num];
      }
      */
}
