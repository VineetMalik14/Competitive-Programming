#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(1000005)
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

ll diff=0;
ll n, m; 
vll vis(mox), cnt(mox), g[mox], st;

ll dfs(ll x){
	vis[x]=1;
	st.pb(x);
	ll r=1;
	fol(i,0,g[x].size()){
		ll u=g[x][i];
		if(vis[u]==0){
			r+=dfs(u);
			if(u>n){
				diff++;
			}
		}
	}
	return r;
}
void dfs1(ll x){
	vis[x]=1;
	fol(i,0,g[x].size()){
		ll u=g[x][i];
		if(vis[u]==0){
			cnt[u]=cnt[x];
			dfs1(u);
		}
	}
}
int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	fol(i,0,m){
		ll k; cin>>k;
		fol(j,0,k){
			ll t; cin>>t;
			g[n+1+i].pb(t);
			g[t].pb(n+1+i);
		}
	}
	fol(i,1,n+1){
		if(cnt[i]==0){
			st.clear();
			diff=0;
			cnt[i]=dfs(i)-diff;
			fol(j,0,st.size()){
				vis[st[j]]=0;
			}
			dfs1(i);
			fol(j,0,st.size()){
				vis[st[j]]=0;
			}
		}
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	return 0;
}