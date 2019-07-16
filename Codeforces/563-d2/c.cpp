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

ll isprime(ll x){
	ll p=sqrt(x)+1;
	if(x==2){
		return 1;
	}
	for(ll i=2; i<=p; i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	vll v, a(n+1);
	fol(i,2,n+1){
		if(isprime(i)){
			v.pb(i);
		}
	}
	ll r=1;
	fol(i,0,v.size()){
		ll t=v[i];
		for(ll j=t; j<=n; j+=t){
			a[j]=r;
		}
		r++;
	}
	fol(i,2,n+1){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}