#include <iostream>
using namespace std;
typedef long long ll;
#define N 51
#define mod 1000000007
ll ar[N][N];
ll I[N][N];

void mul(ll a[][N],ll b[][N],ll m)
{
	ll res[m+1][m+1];
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{

			res[i][j]=0;
			for(ll k=0;k<m;k++)
			{
				res[i][j] = (res[i][j] % mod + ((a[i][k] % mod) * (b[k][j] % mod) % mod)) % mod;
			}
		}
	}
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			a[i][j]=res[i][j];
		}
	}
}

void power(ll a[][N],ll m,ll n)
{
	for(ll i=0;i<m;i++)
	for(ll j=0;j<m;j++)
	{
		if(i==j) I[i][j]=1;
		else I[i][j]=0;
	}
	while(n)
	{
		if(n%2)
		{
			mul(I,a,m);
			n--;
		}
		else
		{
			mul(a,a,m);
			n/=2;
		}
	}

	for(ll i=0;i<m;i++)
	for(ll j=0;j<m;j++)
	a[i][j]=I[i][j];
}

void printMat(ll ar[][N],int m,int n)
{
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	ll t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(ll i=0;i<m;i++)
		{
            for(ll j=0;j<m;j++)
            {
                cin>>ar[i][j];
            }
		}
		power(ar,m,n);
		printMat(ar,m,n);
	}
	return 0;
}
