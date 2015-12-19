const int maxN = 51;
ld derr[maxN];
void derrangement ()
{
	derr[0] = 1;
	derr[1] = 0;
	for(int i = 2; i < maxN; i++)
	{
		derr[i] = (i-1) * ( derr[i-1] + derr[i-2] );  
	}
}
