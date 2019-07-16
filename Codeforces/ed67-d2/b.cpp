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

	ll n; cin>>n;
	string s; cin>>s;
	vector < vector <ll> > v(26, vector<ll>(n));
	fol(i,0,n){
		v[s[i]-'a'][i]=1;
	}
	fol(i,0,26){
		fol(j,1,n){
			v[i][j]+=v[i][j-1];
		}
	}
	ll m; cin>>m;
	while(m--){
		string t; cin>>t;
		ll n1=t.length();
		vll c(26);
		fol(i,0,n1){
			c[t[i]-'a']++;
		}
		ll ans=0;
		fol(i,0,26){
			ll k=lower_bound(v[i].bb, v[i].ee, c[i])-v[i].bb;
			ans=max(ans, k);
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}