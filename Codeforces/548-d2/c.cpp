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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll grand(ll x) {
    return uniform_int_distribution<ll>(0, x-1)(rng);
}

ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return (r*r)%mod; 
    	else		return (x*((r*r)%mod))%mod; 
}

ll ans=0, k;
vll g[mox], vis(mox);
vector<bool> tal[mox];

ll dfs(ll x){
	vis[x]=1;
	ll tot=1;
	fol(i,0,g[x].size()){
		ll v=g[x][i];
		if(!vis[v]){
			ll r=dfs(v);
			if(!tal[x][i]){
				tot+=r;
			}
			else{
				ans+=mod-pw(r, k);
				ans%=mod;
			}
		}
	}
	return tot;
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n>>k;
	fol(i,0,n-1){
		ll u, v, x;cin>>u>>v>>x;
		g[u].pb(v); g[v].pb(u);
		tal[u].pb(x); tal[v].pb(x);
	}
	
	ll r=dfs(1);
	ans+=pw(n, k)+mod-pw(r, k);
	cout<<ans%mod<<endl;
	return 0;
}