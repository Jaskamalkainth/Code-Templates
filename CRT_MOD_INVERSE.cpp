/*
 *
 *  Extended Euclid Algo
 *  Chinese Remainder Theorem
 * 
 * 	Modular Inverse
 *  find x such that a*x = 1 mod n 
 *
 *
 *  Find all soltuions to a*x = b mod n 
 */


const int MAX = 10005;
ll powmod(ll a, ll b, ll m)
{
	if ( m == 0 ) return 0;
	ll oo = 1e9;
	if (a < oo && b < oo)
		return (a * b) % m;
	ll ans = 0;
	for (; b; b >>= 1)
	{
		if (b & 1)
			ans = (ans + a) % m;
        a = (a + a) % m;
    }
    return ans;
}

ll mod(ll a, ll b)
{
	if( b == 0 ) 
		return 0 ; 
    return ((a % b) + b) % b;
}


// returns d = gcd(a,b); finds x,y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    ll xx = y = 0;
    ll yy = x = 1;
    while (b)
    {
        ll q = a / b;
        ll t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
// finds all solutions to ax = b (mod n)
vi modular_linear_equation_solver(ll a, ll b, ll n)
{
    ll x, y;
    vi solutions;
    ll d = extended_euclid(a, n, x, y);
    if (!(b % d))
    {
        x = mod(x * (b / d), n);
        for (ll i = 0; i < d; i++)
            solutions.push_back(mod(x + i * (n / d), n));
    }
    return solutions;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
ll mod_inverse(ll a, ll n)
{
    ll x, y;
    ll d = extended_euclid(a, n, x, y);
    if (d > 1)
        return -1;
    return mod(x, n);
}


// Chinese remainder theorem (special case):
// Find z such that
// z % x = a
// z % y = b. 
// Here, z is unique modulo M = lcm(x,y).
// Return (z,M).  
// On failure, M = -1.
pll chinese_remainder_theorem(ll x, ll a, ll y, ll b)
{
    ll s, t;
    ll d = extended_euclid(x, y, s, t);
    if (a % d != b % d)
        return make_pair(0, -1);

    ll tmp = powmod(s, b, x * y);
    tmp = powmod(tmp, x, x * y);

    ll aux = powmod(t, a, x * y);
    aux = powmod(aux, y, x * y);

    return make_pair(mod(tmp + aux, x * y) / d, x * y / d);
}

// z % x[i] = a[i]
// z = a[i] mod x[i] 

//pll.ff returnsz value 
//pll.ss returns LCM ( x[0..n] )
//
// Chinese remainder theorem: 
//
// find z such that
// z % x[i] = a[i] for aLL i. 
//
// Note that the solution is
// unique modulo M = lcm_i (x[i]).  
//
// Return (z,M).  
// On failure, M = -1.  
//
// Note that we do not require the a[i]'s to be relatively prime.
pll chinese_remainder_theorem(const vll &x, const vll &a)
{
    pll ret = make_pair(a[0], x[0]);
    for (ll i = 1; i < (int) x.size(); i++)
    {
        ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
        if (ret.second == -1)
            break;
    }
    return ret;
}

