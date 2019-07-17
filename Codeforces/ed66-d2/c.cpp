#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
#define inf ll(1e18)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define vll vector<ll>
#define mk make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()


ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		ll n, k; cin>>n>>k;
		vll a(n+1);
		fol(i,0,n){
			cin>>a[i];
		}
		ll ans=mod, pos=0;
		fol(i,k,n){
			ll d1=(a[i]+a[i-k])/2;
			ll f1=max(d1-a[i-k], a[i]-d1);
			if(ans>f1){
				ans=f1;
				pos=d1;
			}
		}
		cout<<pos<<endl;
	}
	return 0;
}