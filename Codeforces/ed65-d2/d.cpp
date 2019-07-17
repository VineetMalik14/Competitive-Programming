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
	string s; cin>>s;
	vll ans(n), vt(1);
	vt[0]=0;
	fol(i,0,n){
		if(s[i]=='('){
			ans[i]=vt[vt.size()-1];
			vt.pb(abs(vt[vt.size()-1]-1));
		}
		else{
			ans[i]=abs(vt[vt.size()-1]-1);
			vt.po();
		}
	}
	fol(i,0,n){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}