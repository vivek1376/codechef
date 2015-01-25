#include <iostream>

using namespace std;

int main()
{
    int T,N,K,i,j,k;
    unsigned long long int sum,X,S[22],bMask,bMax,newMask;
    char **dp;

    cin>>T;
    
    while(T--)
    {
	cin>>N>>K;
	
	i=0,j=N,sum=0;
	while(j--)
	{
	    cin>>S[i++];
	    sum+=S[i-1];
	}

	if(sum%K)
	{
	    cout<<"no"<<endl;
	    continue;
	}

	// required sum of each subset
	X=sum/K;

	bMax=(1<<N)-1;

	// store yes-no values
	dp=new char*[9];
	for(i=0;i<9;i++)
	    dp[i]=new char[1<<21];
	
	for(i=0;i<9;i++)
	    for(j=0;j<(1<<21);j++)
		dp[i][j]=0;
	
	dp[0][0]=1;
	for(k=0;k<K;k++)
	{
	    for(bMask=0;bMask<=bMax;bMask++)
	    {
		if (dp[k][bMask]==0)
		    continue;

		sum=0;
		for(i=0;i<N;i++)
		    if(bMask & (1<<i))
			sum+=S[i];
		
		sum=sum-k*X;
		
		for(i=0;i<N;i++)
		{
		    if(bMask & (1<<i))
			continue;//already present in bitmask
		    
		    newMask=bMask|(1<<i);
		    
		    if(sum+S[i]==X)
			dp[k+1][newMask]=1;
		    else if (sum+S[i]<X)
			dp[k][newMask]=1;
		}
	    }
	}
	
	if (dp[K][bMax]==1)
	    cout<<"yes"<<endl;
	else
	    cout<<"no"<<endl;
	
	// free memory
	for(i = 0; i < 9; ++i) 
	    delete [] dp[i];
    
	delete [] dp;

    }
    return 0;
}
