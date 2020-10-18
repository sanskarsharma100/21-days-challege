#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int arr[1000001];
int pp[1000001];

int sieve()
{
	int mNum=1000000;
	for(ll i=0;i<=mNum;i++) arr[i]=1;
	arr[0]=arr[1]=0;
	for(ll i=2;i<=mNum;i++)
	{
		if(arr[i]==1)
		{
			for(ll j=i*i;j<=mNum;j+=i)
			{
				arr[j]=0;
			}
		}
	}
	int cnt=0;
	for(ll i=0;i<=mNum;i++)
	{
		if(arr[i]==1)
		cnt++;
		if(arr[cnt]==1)
		{
			pp[i]=1;
		}
		else
		pp[i]=0;
	}

	for(ll i=0;i<=mNum;i++)
	{
		pp[i]+=pp[i-1];
	}
}

int main()
{
    sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int L,R;
		cin>>L>>R;
		int count=pp[R]-pp[L-1];
		cout<<count<<endl;
	}
}
