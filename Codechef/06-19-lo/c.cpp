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
		vll a(n), b(n);
		fol(i,0,n){
			cin>>a[i];
		}
		ll k, x; cin>>k>>x;
		ll sum=0, xsum=0, ideal=0, g1=0, gall=0, r=0;
		fol(i,0,n){
			b[i]=a[i]^x;
			sum+=a[i];
			xsum+=b[i];
			if(b[i]>a[i]){
				r++;
			}
			ideal+=max(a[i], b[i]);
		}
		gall=max(sum, xsum);
		if(x==0){
			cout<<sum<<"\n";
			continue;
		}
		ll val1=-inf, val2=inf;
		fol(i,0,n){
			if(b[i]<a[i]){
				val1=max(val1, b[i]-a[i]);
			}
			else{
				val2=min(val2, b[i]-a[i]);
			}
		}
		g1=max(ideal+val1, ideal-val2);
		if(r==k){
			cout<<ideal<<"\n";
			continue;			
		}
		if(r>k){
			if(r%k==0){
				cout<<ideal<<"\n";
				continue;
			}
			ll d=r%k;
			if(d%2==0){
				cout<<ideal<<"\n";
				continue;
			}
			if(k%2==1){
				cout<<ideal<<"\n";
				continue;
			}
			cout<<g1<<"\n";
			continue;
		}
		if(r%2==0){
			if(n>=k+1){
				cout<<ideal<<"\n";
				continue;
			}
			cout<<gall<<"\n";
			continue;
		}
		if(k%2==1){
			if(n>=k+1){
				cout<<ideal<<"\n";
				continue;
			}
			cout<<gall<<"\n";
			continue;
		}
		if(n>=k+1){
			cout<<g1<<"\n";
			continue;
		}
		cout<<gall<<"\n";
		continue;
	}
	return 0;
}