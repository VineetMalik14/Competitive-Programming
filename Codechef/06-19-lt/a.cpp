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
		ll n, q; cin>>n>>q;
		ll s=0;
		map <ll,ll> mp;
		fol(i,0,q){
			ll ty; cin>>ty;
			if(ty==1){
				ll y; cin>>y;
				ll x=s+y;
				mp[x]=1;
			}
			else{
				ll p1, q1; cin>>p1>>q1;
				ll l=p1+s, r=q1+s;
				ll j=r, ans=0;
				vll v;
				while(mp[j]){
					v.pb(j);
					j-=mp[j];
				}  
				if(j>=l){
					ans=j;
				}
				for(ll k=v.size()-2; k>=0; k--){
					mp[v[k]]+=mp[v[k+1]];
				}
				cout<<ans<<"\n";
				s+=ans;
				s%=n;
			}
		}
	}
	return 0;
}