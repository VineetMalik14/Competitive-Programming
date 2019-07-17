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
	vector < pair<ll,ll> > v1, v2;
	map <ll,ll> mp;
	ll c1=0;
	fol(i,0,n){
		ll x, y; cin>>x>>y;
		v1.pb(mk(x, y));
		v2.pb(mk(y, x));
		if(mp[x]==0){
			c1++;
		}
		mp[x]++;
	}
	sort(v2.bb, v2.ee);
	ll ans=(c1*(c1+1))/2;
	fol(i,0,n){
		ll i1=i;
		vll vt;
		while(i1<n && v2[i].ff==v2[i1].ff){
			mp[v2[i1].ss]--;
			if(mp[v2[i1].ss]==0){
				mp.erase(v2[i1].ss);
			}
			else{
				vt.pb(v2[i1].ss);
			}
			i1++;
		}
		ll rk=0;
		fol(j,0,vt.size()){
			ll p1=0;//mp.find(vt[j])-mp.bb;
			ans+=(mp.size()-1-p1)*(p1-rk)+(mp.size()-1-rk);
			rk=p1+1;
		}
		
		i=i1-1;
	}
	cout<<ans<<"\n";
	return 0;
}