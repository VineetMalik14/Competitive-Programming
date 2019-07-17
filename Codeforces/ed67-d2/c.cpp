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

	ll n, m; cin>>n>>m;
	vll a(n+1);
	vector < pair<ll,ll> > v, v1;
	ll k=mod-7;
	fol(i,1,n+1){
		a[i]=k;
		k-=2;
	}
	fol(i,0,m){
		ll t, l, r; cin>>t>>l>>r;
		if(t){
			v1.pb(mk(l, r));
		}
		else{
			v.pb(mk(r, l));
		}
	}
	sort(v1.bb, v1.ee);
	fol(i,0,v1.size()){
		ll l=v1[i].ff, r=v1[i].ss;
		while(i<v1.size() && r>=v1[i].ff){
			r=max(r, v1[i].ss);
			i++;
		}
		i--;
		fol(j,l,r+1){
			a[j]=k;
		}
		k-=2;
	}
	sort(v.bb, v.ee);
	fol(i,0,v.size()){
		ll ok=0, l=v[i].ss, r=v[i].ff;
		fol(j,l,r){
			if(a[j]>a[j+1]){
				ok=1;
			}
		}
		if(!ok){
			if(a[r]==a[r-1]){
				cout<<"NO\n";
				return 0;
			}
			else{
				fol(j,l,r){
					a[j]=a[r]+1;
				}
			}
		}
	}
	cout<<"YES\n";
	fol(i,1,n+1){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}