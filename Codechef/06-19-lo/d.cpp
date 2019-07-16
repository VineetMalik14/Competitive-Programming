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

ll n, q; 
vll pt, g[1005];

ll dfs(ll x, ll p){
	ll r=1;
	fol(i,0,g[x].size()){
		ll u=g[x][i].ff;
		if(u==p){
			pos=i;
		}
		else{
			ll temp=dfs(u, x);
			r+=temp;
			g[x][i].ss=temp;
		}
	}
	g[x][pos].ss=n-r;
	return r;
}

bool path(ll u, ll p, ll x, ll v){
	if(x==v){
		pt.pb(x);
		return true;
	}
	fol(i,0,g[x].size()){
		if(g[x][i].ff!=p){
			if(path(u, x, g[x][i].ff, v)){
				pt.pb(x);
				return true;
			}
		}
	}
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		cin>>n>>q;
		fol(i,0,1005){
			g[i].clear();
		}
		fol(i,0,n-1){
			ll u, v; cin>>u>>v;
			g[u].pb(mk(v, 0)); g[v].pb(mk(u, 0));
		}
		dfs(1, 0);
		fol(i,0,q){
			ll u, v; cin>>u>>v;
			pt.clear();
			path(u, 0, u, v);
			ll ans=pt.size();
			if(pt.size()==1){
				ans+=((n*(n-1))/2)%mod;
				ans%=mod;
				fol(i,0,g[pt[o]].size()){
					ans+=((g[pt[0]][i].ss*(g[pt[0]][i].ss-1))/2)%mod;
					ans%=mod;
				}
			}
			else{
				ll l=pt.size();
				ll k1=g[pt[0]][pt[1]].ss, k2=g[pt[l-1]][pt[l-2]].ss;
				ll tt1=(((n-k1)*(n-k1-1))/2)%mod;
				ll tt2=(((n-k2)*(n-k2-1))/2)%mod;
				ans+=tt1+tt2;
				ans%=mod;
				ans+=mod-((k1*(k1-1))/2)%mod;
				ans%=mod;
				ans+=mod-((k2*(k2-1))/2)%mod;
				ans%=mod;
				fol(i,1,l-1){
					ll k1=g[pt[i]][pt[i+1]].ss, k2=g[pt[i]][pt[i-1]].ss;
					ll u1=g[pt[i]][pt[i+1]].ss, u2=g[pt[i]][pt[i-1]].ss;
					ll k3=k1+k2;
					ll tt1=(((n-k3)*(n-k3-1))/2)%mod;
					fol(j,0,g[pt[i]].size()){
						if(g[pt[i]][j].ff!=u1 && g[pt[i]][j].ff	!=u2){
							ll k1=g[pt[i]][j].ss;
							ans+=mod-((k1*(k1-1))/2)%mod;
					ans%=mod;
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}