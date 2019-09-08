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
		ll n; cin>>n;
		vll a(n);
		fol(i,0,n){
			cin>>a[i];
		}
		sort(a.bb, a.ee);
		a.resize(distance(a.bb, unique(a.bb, a.ee)));
		n=a.size();
		if(n==1){
			cout<<2*a[0]<<"\n";
		}
		else{
			vll pg(n), sg(n);
			pg[0]=a[0];
			fol(i,1,n){
				pg[i]=gcd(a[i], pg[i-1]);
			}
			sg[n-1]=a[n-1];
			fol(i,1,n){
				ll j=n-1-i;
				sg[j]=gcd(a[i], sg[j+1]);
			}
			ll ans=max(a[0]+sg[1], a[n-1]+pg[n-2]);
			fol(i,1,n-1){
				ans=max(ans, a[i]+gcd(pg[i-1], sg[i+1]));
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}