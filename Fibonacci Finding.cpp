#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mod 1000000007

ll a[3],I[3][3],T[3][3];

void mul(ll A[3][3],ll B[3][3],int m)
{
    ll res[m+1][m+1];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            res[i][j]=0;
            for(int k=1;k<=m;k++)
            {
                ll x=(A[i][k] * B[k][j])%mod;
                res[i][j]=(res[i][j]+x)%mod;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            A[i][j]=res[i][j];
        }
    }
    
}

ll getfibo(int n)
{
    if(n<=2) return a[n];
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;
    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;
    n=n-1;
    while(n)
    {
        if(n%2)
        {
            mul(I,T,2);
            n--;
        }
        else
        {
            mul(T,T,2);
            n/=2;
        }
    }
    ll Fn=((a[1] * I[1][1]% mod)+(a[2]*I[2][1] % mod))% mod;
    return Fn;
}

int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>a[1]>>a[2]>>n;
        n++;
        cout<<getfibo(n)<<endl;

    }
}