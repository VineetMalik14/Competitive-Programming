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

vll g[mox];

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	fol(i,1,n+1){
		ll in1, in2;
		cin>>in1>>in2;
		g[i].pb(in1); g[i].pb(in2);
	}
	if(n==3){
		cout<<1<<" "<<2<<" "<<3<<endl;
		return 0;
	}
	vll ans;
	ans.pb(1);
	fol(j,1,n){
		ll i=ans[ans.size()-1];
		if(g[i][0]==g[g[i][1]][0] || g[i][0]==g[g[i][1]][1]){
			ans.pb(g[i][1]);
		}
		else{
			ans.pb(g[i][0]);
		}
	}
	fol(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}