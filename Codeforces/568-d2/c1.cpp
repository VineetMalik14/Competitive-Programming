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
	vll a(n), ans(n);
	fol(i,0,n){
		cin>>a[i];
	}
	fol(i,0,n){
		sort(a.bb, a.bb+i);
		ll j=i-1;
		ll s=0;
		fol(j,0,i){
			s+=a[j];
		}
		while(m-s<a[i]){
			s-=a[j];
			ans[i]++;
			j--;
		}
	}
	fol(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}