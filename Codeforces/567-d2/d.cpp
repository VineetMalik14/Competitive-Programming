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

	ll n, m, q; cin>>n>>m>>q;
	vll a(n), cnt(m+1);
	fol(i,0,n){
		cin>>a[i];
		cnt[a[i]]++;
	}
	vector < pair <ll,ll> > v1, v2;
	vll aa[900];
	fol(i,1,m+1){
		v1.pb(mk(cnt[i], i));
	}
	sort(v1.bb, v1.ee);
	v2.pb(mk(v1[0].ff, 1));
	fol(i,1,m){
		if(v1[i].ff==v2[v2.size()-1].ff){
			v2[v2.size()-1].ss++;
		}
		else{
			v2.pb(mk(v1[i].ff, 1));
		}
	}
	ll j=0;
	while(j<m && v1[j].ff==v2[0].ff){
		aa[0].pb(v1[j].ss);
		j++;
	}
	vll u1;
	u1.pb(0);
	if(1<v2.size()){
		ll r1=(v2[1].ff-v2[0].ff)*v2[0].ss;
		u1.pb(r1);
	}
	fol(i,1,v2.size()){
		fol(k,0,aa[i-1].size()){
			aa[i].pb(aa[i-1][k]);
		}
		while(j<m && v1[j].ff==v2[i].ff){
			aa[i].pb(v1[j].ss);
			j++;
		}
		sort(aa[i].bb, aa[i].ee);
		if(i!=v2.size()-1){
			ll r1=u1[u1.size()-1]+(v2[i+1].ff-v2[i].ff)*v2[i].ss;
			u1.pb(r1);
		}
	}
	ll t;
	fol(i,0,q){
		cin>>t;
		t-=n;
		ll pos=upper_bound(u1.bb, u1.ee, t)-u1.bb;
		t-=u1[pos-1];
		cout<<aa[pos][((t)%aa[pos].size()-1+aa[pos].size())%aa[pos].size()]<<"\n";
	}
	return 0;
}