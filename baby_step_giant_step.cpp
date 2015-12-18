/*
 *
 * Baby Step Gian step
 * O(root(m) * log m )
 *
 * baby_giant ( a , b , m )
 *
 * returns the least value of x such that a^x = b mod m
 */

const int mod=1e9+7;
const ll  mx_ll   = numeric_limits<ll> :: max();
ll baby_giant (ll a, ll b, ll m) {

	ll fans = mx_ll;

	ll n = (ll) sqrt (m + .0) + 1;

    ll an = 1;
    for (ll i=0; i<n; ++i)
        an = (an * a) % m;

    map<ll,ll> vals;
    for (ll i=1, cur=an; i<=n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }

    for (ll i=0, cur=b; i<=n; ++i) {
        if (vals.count(cur)) {
            ll ans = vals[cur] * n - i;
            if (ans < m && ans != 0 )
			{
				fans = min ( fans , ans );  
			}
        }
        cur = (cur * a) % m;
    }

	if ( fans  == mx_ll )
    	return -1;
	else  
		return fans;

}

