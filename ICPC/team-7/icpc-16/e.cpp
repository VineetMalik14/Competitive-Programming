#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

int power(ll x, unsigned ll y){ 
    if (y == 0) 
        return 1; 
    else if (y%2 == 0) 
        return (power(x, y/2)%mod)*(power(x, y/2)%mod)%mod; 
    else
        return ((x*power(x, y/2)%mod)*(power(x, y/2)%mod))%mod; 
} 
int main(){             // E
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n, c; cin>>n>>c;
                ll a=(power(power(c,n),n)*power(power(c,n/2),(n+1)/2))%mod;
                ll ac4=((((a*(a-1))%mod)*(((a-2)*(a-3))%mod))/4)%mod;
                ll ac3=((((a*(a-1))%mod)*((a-2)%mod))/3)%mod;
                ll ac2=((a*(a-1))/2)%mod;
                ll ac1=a;
        }
	return 0;
}