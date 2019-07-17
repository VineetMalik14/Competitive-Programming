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

	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vll a(n), b(n), v;
		ll l=0, r=0;
		fol(i,0,n){
			cin>>a[i];
		}
		fol(i,0,n){
			cin>>b[i];
		}
		fol(i,0,n){
			if(a[i]!=b[i]){
				l=i;
				break;
			}
		}
		fol(i,0,n){
			if(a[n-1-i]!=b[n-1-i]){
				r=n-1-i;
				break;
			}
		}
		v.pb(l-1);
		fol(i,l,r){
			if(b[i]>b[i+1]){
				v.pb(i);
			}
		}
		v.pb(r);
		fol(i,0,v.size()-1){
			sort(a.bb+v[i]+1, a.bb+v[i+1]+1);
		}
		string ans="YES\n";
		fol(i,0,n){
			if(a[i]!=b[i]){
				ans="NO\n";
			}
		}
		cout<<ans;
	}
	return 0;
}