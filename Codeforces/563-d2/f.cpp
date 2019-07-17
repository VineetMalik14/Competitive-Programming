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


vll vis(mox);
vector < pair<ll,ll> > g[mox];

ll dfs(ll x){
	vis[x]=1;
	ll r=0;
	fol(i,0,g[x].size()){
		ll u=g[x][i].ff;
		if(!vis[u]){
			g[x][i].ss=1+dfs(u);
			r=max(r, g[x][i].ss);
		}
		else{
			g[x][i].ss=-1;
		}
	}
	return r;
}

void solve(ll x, ll d){
	if(d==0){
		cout<<"! "<<x<<endl;
		return;
	}
	ll cnt=0, pos=0;
	fol(i,0,g[x].size()){
		if(g[x][i].ss>=d){
			cnt++;
			pos=g[x][i].ff;
		}
	}
	if(cnt>1){
		cout.flush();
		cout<<"s "<<x<<endl;
		cin>>pos;
	}
	solve(pos, d-1);
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	fol(i,0,n-1){
		ll u, v; cin>>u>>v;
		g[u].pb(mk(v,0));
		g[v].pb(mk(u,0));
	}
	dfs(1);
	ll d=0;
	cout.flush();
	cout<<"d "<<1<<endl;
	cin>>d;
	solve(1, d);
	return 0;
}