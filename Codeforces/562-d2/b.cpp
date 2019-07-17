#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(300005)
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
	vll ans1, ans2;
	vector< pair< pair<ll,ll> , ll > > b(n);
	fol(i,0,n){
		cin>>b[i].ff.ss>>b[i].ff.ff;
		b[i].ss=i+1;
	}
	sort(b.bb, b.ee);
	for(ll i=b.size()-1; i>=0; i--){
		if(b[i].ff.ff>b[i].ff.ss){
			ans1.pb(b[i].ss);
		}
	}
	for(ll i=0; i<=b.size()-1; i++){
		if(b[i].ff.ff<b[i].ff.ss){
			ans2.pb(b[i].ss);
		}
	}
	if(ans1.size()>=ans2.size()){
		cout<<ans1.size()<<endl;
		fol(i,0,ans1.size()){
			cout<<ans1[i]<<" ";
		}
	}
	else{
		cout<<ans2.size()<<endl;
		fol(i,0,ans2.size()){
			cout<<ans2[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}