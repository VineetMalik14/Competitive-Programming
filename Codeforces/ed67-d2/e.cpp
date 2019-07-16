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

ll n;
vll g[mox], d(mox), c(mox);

ll dfs(ll x, ll p){
	ll r=1;
	fol(i,0,g[x].size()){
		ll u=g[x][i];
		if(u!=p){
			r+=dfs(u, x);
		}
	}
	c[1]+=r;
	d[x]=r;
	return r;
}

void dfs1(ll x, ll p){
	c[x]=c[p]+n-d[x]-d[x];
	fol(i,0,g[x].size()){
		ll u=g[x][i];
		if(u!=p){
			dfs1(u, x);
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	fol(i,1,n){
		ll u, v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	fol(i,0,g[1].size()){
		dfs1(g[1][i], 1);
	}
	ll ans=0;
	fol(i,1,n+1){
		ans=max(ans, c[i]);
	}
	cout<<ans<<"\n";
	return 0;
}