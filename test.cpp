#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007

//#ifdef _WINDOWS
// no getchar_unlocked on Windows so just call getchar
inline int getchar_unlocked() { return getchar(); }
//#endif

using namespace std;
 
long long int *pow2s;
int *myset;
 
inline void scanint(int* x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
 
int main()
{
	int T,N,i;
	long long int ans;
	pow2s = (long long int*)malloc(sizeof(long long int)*100010);
	myset = (int*)malloc(sizeof(int)*100010);
 
	pow2s[0] = 1;
	for(i = 1; i < 100010; ++i)
		pow2s[i] = (2*pow2s[i-1]) % MOD;
 
/*	for(i = 0; i < 100010; ++i)
	{
		--pow2s[i];
		if(pow2s[i] < 0) pow2s[i] += MOD;
		}*/
 
	scanint(&T);
	while(T--)
	{
		scanint(&N);
 
		for(i = 0; i < N; ++i)
			scanint(&myset[i]);
 
		sort(myset, myset + N);
 
		ans = 0;
		for(i = 0; i < N; ++i)
		{
//		    printf("pow2s[i]: %lld\n",pow2s[i]);//d
			ans += myset[i]*pow2s[i];
			ans = (ans - (myset[i]*pow2s[N-i-1])) % MOD;
			if(ans < 0) ans += MOD;
		}
 
		printf("%lld\n", ans);
	}
 
	free(myset);
	free(pow2s);
	return 0;
}  
 
