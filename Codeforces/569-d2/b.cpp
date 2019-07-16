#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long int ll;
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
	vll a(n);
	fol(i,0,n){
		cin>>a[i];
		if(a[i]>=0){
			a[i]=-a[i]-1;
		}
	}
	if(n%2==1){
		ll pos=0;
		fol(i,1,n){
			if(a[i]<a[pos]){
				pos=i;
			}
		}
		a[pos]=-a[pos]-1;
	}
	fol(i,0,n){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}