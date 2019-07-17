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

	ll n, q; cin>>n>>q;
	vll a(n);
	deque <ll> dd;
	vector < pair<ll,ll> > ans(1);
	fol(i,0,n){
		cin>>a[i];
		dd.push_back(a[i]);
	}
	fol(i,1,n){
		ll r1=dd.at(0), r2=dd.at(1);
		dd.pop_front(); dd.pop_front();
		ans.pb(mk(r1, r2));
		if(r1>=r2){
			dd.push_front(r1);
			dd.push_back(r2);
		}
		else{
			dd.push_front(r2);
			dd.push_back(r1);
		}
	}
	fol(i,0,q){
		ll m; cin>>m;
		if(m<n){
			cout<<ans[m].ff<<" "<<ans[m].ss<<"\n";
		}
		else{
			cout<<dd.at(0)<<" "<<dd.at(1+(m-n)%(n-1))<<"\n";
		}
	}
	return 0;
}