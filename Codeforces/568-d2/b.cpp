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
	fol(i,0,n){
		string a, b; cin>>a>>b;
		vll v1, v2, c1, c2;
		v1.pb(a[0]); c1.pb(1);
		v2.pb(b[0]); c2.pb(1);
		fol(i,1,a.length()){
			if(a[i]==a[i-1]){
				c1[c1.size()-1]++;
			}
			else{
				v1.pb(a[i]); c1.pb(1);
			}
		}
		fol(i,1,b.length()){
			if(b[i]==b[i-1]){
				c2[c2.size()-1]++;
			}
			else{
				v2.pb(b[i]); c2.pb(1);
			}
		}
		if(v1.size()!=v2.size()){
			cout<<"NO\n";
		}
		else{
			ll ok=1;
			fol(i,0,v1.size()){
				if(v1[i]!=v2[i] || c1[i]>c2[i]){
					ok=0;
					break;
				}
			}
			if(ok){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}