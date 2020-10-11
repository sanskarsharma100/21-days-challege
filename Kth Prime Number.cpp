#include<bits/stdc++.h>
using namespace std;
int Pnum[5000000];
bool arr[86028122];

void Find()
{
    int mNum=86028122;
   
    for(int i=2;i*i<=mNum;i++)
    {
        if(!arr[i])
        {
            for(int j=i*i;j<=mNum;j+=i)
            {
                arr[j]=true;
            }
        }
    }
    int j=0;
    for(int i=2;i<=mNum;i++)
    {
        if(!arr[i])
        {
        	Pnum[j++]=i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    Find();
    while(t--)
    {
        int n;
        cin>>n;
        cout<<Pnum[n-1]<<endl;
    }
}