vector<ll> getDivisors(ll n)
{
    set<ll> fcd;
    for(ll i = 1; i * i <= n ; i++)
    {
        if ( n % i == 0 )
        {
            fcd.insert(i);
            fcd.insert(n/i);
        }
    }
    vector<ll> cd;
    for(auto x: fcd)
        cd.push_back(x);

    return cd;
}

