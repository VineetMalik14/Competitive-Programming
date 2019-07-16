#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll a, b,x, y;
        cin>>a>>b>>x>>y;
        ll k1=__gcd(x,y);
        ll k2=(a)/(x/k1), k3=(b)/(y/k1);
        ll ans=min(k2,k3);
        cout<<ans<<endl;
    	return 0;
}