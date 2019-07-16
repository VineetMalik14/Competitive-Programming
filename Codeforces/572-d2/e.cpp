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

	ll n, p, k; cin>>n>>p>>k;
	vll a(n);
	map <ll,ll> ck;
	vll v1[n];
	fol(i,0,n){
		cin>>a[i];
		ck[a[i]]=1;
	}

	vll f;
	for(ll i=1; i*i<=k; i++){
		if(k%i==0){
			if(i!=k/i){
				f.pb(k/i);
			}
			f.pb(i);
		}
	}
	for(ll i=1; i*i<=k+p; i++){
		if((k+p)%i==0){
			if(i!=(k+p)/i){
				f.pb((k+p)/i);
			}
			f.pb(i);
		}
	}
	sort(f.bb, f.ee);
	f.resize(distance(f.bb, unique(f.bb, f.ee)));
	cout<<f.size()<<"\n";
	fol(i,0,f.size()){
		fol(j,0,n){
			ll r2=f[i]-a[j];
			if(r2<p && r2>=0 && r2!=a[j] && (f[i]*((a[j]*a[j]+r2*r2)%p))%p==k){
				v1[j].pb(r2);
			}
			r2=p+f[i]-a[j];
			if(r2<p && r2>=0 && r2!=a[j] && (f[i]*((a[j]*a[j]+r2*r2)%p))%p==k){
				v1[j].pb(r2);
			}
			r2=(p+f[i]-a[j])%p;
			if(r2<p && r2>=0 && r2!=a[j] && (f[i]*((a[j]*a[j]+r2*r2)%p))%p==k){
				v1[j].pb(r2);
			}
		}
	}


	ll ans=0;
	fol(i,0,n){
		//cout<<v1[i].size();
		sort(v1[i].bb, v1[i].ee);
		v1[i].resize(distance(v1[i].bb, unique(v1[i].bb, v1[i].ee)));
		fol(j,0,v1[i].size()){
			if(ck[v1[i][j]]){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}