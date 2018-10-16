int Fibo(int n)
{
	unsigned long long int fb[1000];
	fb[0] = 1;
	fb[1] = 1;
	for(int i=2; i<n+1; i++)
		fb[i] = fb[i-1] + fb[i-2];
	return fb[n];
}