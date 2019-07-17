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

	ll n, m; cin>>n>>m;
	set <ll> g[n+1];
	vll d(n+1);
	vector < pair<ll,ll> > c(n+1);
	fol(i,0,m){
		ll u, v; cin>>u>>v;
		g[u].insert(v); g[v].insert(u);
	}
	fol(i,1,n+1){
		c[i].ff=g[i].size()/2;
		c[i].ss=i;
		d[i]=c[i].ff;
	}
	sort(c.bb, c.ee);
	set < pair<ll,ll> > ans;
	fol(k,1,n+1){
		ll i=c[k].ss;
		set <ll> :: iterator it;
		vll v;
		for(it=g[i].bb; it!=g[i].ee; it++){
			v.pb(*it);
		}
		fol(j,0,v.size()){
			if(d[i]!=0 && d[v[j]]!=0){
				g[i].erase(v[j]); g[v[j]].erase(i);
				d[i]--; d[v[j]]--;
			}
		}
		for(it=g[i].bb; it!=g[i].ee; it++){
			ans.insert(mk(min(i, *it), max(i, *it)));
		}
	}
	cout<<ans.size()<<"\n";
	set < pair<ll,ll> > :: iterator it;
	for(it=ans.bb; it!=ans.ee; it++){
		cout<<(*it).ff<<" "<<(*it).ss<<"\n";
	}
	return 0;
}