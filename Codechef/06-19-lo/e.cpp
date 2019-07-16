#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(300005)
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
    	if(y%2==0) 	return (r*r)%mod; 
    	else		return (x*((r*r)%mod))%mod; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	map<ll,ll> mp;
	ll fact[mox];
	fact[0]=1;
	fol(i,1,mox){
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
	}

	ll n, q; cin>>n>>q;
	vll a(n);
	fol(i,0,n){
		cin>>a[i];
	}
	if(n<=1000 && q<=1000){
		ll l1, l2, r1, r2, l, r, p=0;
		fol(i,0,q){
			cin>>l1>>l2>>r1>>r2;
			l=(l1*p+l2)%n; r=(r1*p+r2)%n;
			if(l>r){
				swap(l,r);
			}
			ll ans=fact[r-l+1], dd=1;
			fol(j,l,r+1){
				mp[a[j]]++;
				dd*=mp[a[j]];
				dd%=mod;
			}
			p=(ans*pw(dd,mod-2))%mod;
			cout<<p<<"\n";
			fol(j,l,r+1){
				mp[a[j]]=0;
			}
		}
	}
	else{
		ll l, r;
		fol(i,0,q){
			cin>>l; cin>>l; cin>>r; cin>>r;
			v1.pb(mk(mk(l,r), i));
		}
		sort(v1.bb, v1.ee);
		while(){
			if(v1[i].ff.ff>=v1[i-1].ff.ss){
				arc++;
			}
			else if(v1[i].ff.ss>=v1[i-1].ff.ss)
		}
	}
	return 0;
}