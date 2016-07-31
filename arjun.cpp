#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n ,w, q;
	while(1)
	{
		cout << __builtin_popcount(~scanf("%d%d%d",&n,&q,&w)) << "\n";  
		cout << (cin >> n >> q >> w) << "\n";  
		break;
	}
	return 0;
}
