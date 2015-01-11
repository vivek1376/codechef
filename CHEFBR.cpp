#include <iostream>
//#include <cinttypes>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int N,i=0,j,p,q,r,m,n,o;
    int A[100];
    int modBase=1000000007;
    long long int pr=0;
    cin>>N;

    int dp[100][100]={0};

    i=0,m=N;
    while(m--)
	cin>>A[i++];

    // print
//    for(j=0;j<i;j++)
//	cout<<A[j]<<endl;

    // build map of element and list of positions for each element
    unordered_map<int,vector<int> > occurences;
    unordered_map<int, vector<int> >::iterator iMap;

    for(i=0;i<N;i++)
    {
	occurences[A[i]].push_back(i);
/*	iMap=occurences.find(A[i]);

	if(iMap!=occurences.end())
	{		     
	    (iMap->second).push_back(i);
	    }*/
    }

    vector<int>::iterator iVec;
/*
    for(iMap=occurences.begin();iMap!=occurences.end();++iMap)
    {
	cout<<iMap->first<<" : ";
	for(iVec=iMap->second.begin();iVec!=iMap->second.end();++iVec)
	    cout<<*iVec<<" ";

	cout<<endl;
	}*/
//        unordered_map<int, vector<int> >::key_type num=4; //d
//    cout<<dp[22][43]<<endl;//d

    for(p=1;p<=N-1;p++)
    {
	for(i=0,j=i+p;j<=N-1;++i,j=i+p)
	{
	    dp[i][j]=dp[i][j-1]; //initialize

	    if (A[j]<0)
		continue; 	// exit this iteration

	    iMap=occurences.find(-A[j]);
	    if(iMap!=occurences.end())
	    {   // exist
		for(iVec=iMap->second.begin();iVec!=iMap->second.end();++iVec)
		    // iterate over all positions which fall in range
		    if(*iVec>=i && *iVec<j)
			if(*iVec==0)
			{
			    pr=((1+dp[0][0])*(dp[1][j-1]+1))%modBase;
			    dp[i][j]=(dp[i][j]+pr)%modBase;
//			    dp[i][j]+=((1+dp[0][0])*(dp[1][j-1]+1));
			}
			else
			{
			    pr=((1+dp[i][*iVec-1])*(dp[*iVec+1][j-1]+1))%modBase;
			    dp[i][j]=(dp[i][j]+pr)%modBase;
//			    dp[i][j]+=((1+dp[i][*iVec-1])*(dp[*iVec+1][j-1]+1));
			}
	    }
//	    j=i+p;
	}
    }
    cout<<(dp[0][N-1]+1)%modBase<<endl;

    
    return 0;
}
