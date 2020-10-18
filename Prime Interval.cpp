#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n==1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int L,R;
    cin>>L>>R;
    while(L<=R)
    {
        if(isPrime(L))
        cout<<L<<" ";
        L++;
    }
    cout<<endl;
}