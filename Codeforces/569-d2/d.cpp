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
	fol(i,0,n/2){
		ll r1=1+i, r2=n-i, c1=1, c2=m;
		fol(j,0,2*m){
			if(j%2==0){
				cout<<r1<<" "<<c1<<"\n";
				c1++;
			}
			else{
				cout<<r2<<" "<<c2<<"\n";
				c2--;
			}
		}
	}
	if(n%2==1){
		ll r=(n+1)/2, c1=1, c2=m;
		fol(i,0,m){
			if(i%2==0){
				cout<<r<<" "<<c1<<"\n";
				c1++;
			}
			else{
				cout<<r<<" "<<c2<<"\n";
				c2--;
			}
		}
	}
	return 0;
}