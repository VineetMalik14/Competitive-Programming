#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
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
	ios :: sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);

	ll n, k; cin>>n>>k;
	vll a(n);
	ll e1=0, e2=0;
	fol(i,0,n){
		cin>>a[i];
		if(a[i]==1){
			e1++;
		}
		else{
			e2++;
		}
	}
	ll ans=0;
	fol(j,0,n){
		ll c=j, l1=0, l2=0;
		while(c>=0){
			if(a[c]==1){
				l1++;
			}
			else{
				l2++;
			}
			c-=k;
		}
		c=j+k;
		while(c<n){
			if(a[c]==1){
				l1++;
			}
			else{
				l2++;
			}
			c+=k;
		}
		ans=max(ans,abs((e1-l1)-(e2-l2)));
	}
	cout<<ans<<endl;
	return 0;
}