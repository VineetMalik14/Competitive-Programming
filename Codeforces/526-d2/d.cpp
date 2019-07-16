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

vll g[mox], v(mox), ans;
set<ll> s1;

void dfs(ll x){
		fol(i,0,g[x].size()){
			ll u=g[x][i];
			if(!v[u]){
				s1.insert(u);
			}
		}
		while(!s1.empty()){
			ll k= *s1.bb;
			s1.erase(k);
			ans.pb(k);
			v[k]=1;
			dfs(k);
		}
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, m; cin>>n>>m;
	fol(i,0,m){
		ll u1, u2; cin>>u1>>u2;
		g[u1].pb(u2);
		g[u2].pb(u1);
	}
	fol(i,1,n+1){
		sort(g[i].bb, g[i].ee);
	}
	ans.pb(1); v[1]=1;
	dfs(1);
	fol(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}