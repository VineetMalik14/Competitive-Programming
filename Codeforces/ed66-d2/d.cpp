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

	ll n, k; cin>>n>>>k;
	vll a(n);
	fol(i,0,n){
		cin>>a[i];
	}
	for(i=n-1; i>=0; i--){
		s+=a[i];
		ps[i]=s;
	}
	ll mx=-inf;
	fol(i,0,n){
		if(ps[i]>=mx){
			mx=ps[i]
			pos[i]=i;
		}
		else{
			pos[i]=pos[i-1];
		}
	}
	for(ll i=k; i>=1; i--){
		if(j-pos[j]+1)
	}
	return 0;
}