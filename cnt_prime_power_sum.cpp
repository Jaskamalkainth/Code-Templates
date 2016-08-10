const int maxN = 1e6+7;
int cnt_prime_powers[maxN];
inline void pre()
{
	for(int i = 2; i < maxN; i++)
	{
		if(cnt_prime_powers[i]) continue;
		for(int j = i; j < maxN; j += i)
		{
			int num = j;
			while( num%i == 0) {
				cnt_prime_powers[j]++; 
				num /= i;
			}
		}
	}
}
// cnt_prime_powers[i] : sum of prime powers in the factorisation of i

