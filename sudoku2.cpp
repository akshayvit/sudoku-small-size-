#include <bits/stdc++.h>
#include <time.h>
using namespace std;
typedef long long ll;

vector<vector<ll> > m;

bool anyzero(ll& i,ll& j,ll n)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!m[i][j])
			  return false;
		}
	}
	return true;
}

bool issafe(ll n,ll r,ll c,ll a)
{
	if(m[r][c]!=0)
	  return false;
	for(ll i=0;i<n;i++)
	{
		if(m[i][c]==a)
		   return false;
	}
	for(ll i=0;i<n;i++)
	{
		if(m[r][i]==a)
		   return false;
	}
	ll n1=sqrt(n);
	ll r1=r/n1,c1=c/n1;
	r1*=n1,c1*=n1;
	for(ll i=r1;i<r1+n1;i++)
	{
		for(ll j=c1;j<c1+n1;j++)
		{
			if(m[i][j]==a)
			   return false;
		}
	}
	return true;

}


bool sudoku(ll n)
{
	ll i(0),j(0);
	if(anyzero(i,j,n))
	  return true;
	for(ll a=1;a<=n;a++)
	{
		if(issafe(n,i,j,a))
		{
			m[i][j]=a;
			if(sudoku(n))
			  return true;
			m[i][j]=0;
		}
	}

return false;
}

main()
{
	ll n;
	cin>>n;
	m.resize(n*n);
	for(ll i=0;i<n*n;i++)
	  m[i].resize(n*n);
	clock_t a12,b1,c1;
	a12=clock();
	bool a1=sudoku(n*n);
	b1=clock();
	c1=(double)(b1-a12)/(double)CLOCKS_PER_SEC;
	cout<<"I took only "<<c1<<" milliseconds to solve\n.";
	if(!a1)
	   printf("Not Found\n");
    else
    {
    	for(ll i=0;i<n*n;i++)
    	{
    		for(int j=0;j<n*n;j++)
    		{
    			if(j%n==n-1)
    			cout<<m[i][j]<<" | ";
    			else
    			{
    				if((i%n)!=n-1)
    			cout<<m[i][j]<<"  ";
    			else
    			 cout<<m[i][j]<<"__";
    		}
			}
			printf("\n");
		}
	}
}
