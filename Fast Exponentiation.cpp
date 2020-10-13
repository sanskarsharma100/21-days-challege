#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll m=1000000007;
	int t;
	cin>>t;
	while(t--)
	{
	    ll a,b,res=1;
	    cin>>a>>b;
	    while(b)
	    {
	        if(b%2)
	        {
	            res=(res*a)%m;
	            b--;
	        }
	        else
	        {
	            a=(a*a)%m;
	            b/=2;
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}
