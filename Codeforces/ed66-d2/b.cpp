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

	ll l; cin>>l;
	ll mx=pw(2,32)-1;
	ll k=1, ans=0, ok=1;
	vll v;
	ll rmin=0, p=1, sb=1;
	while(l--){
		string s; cin>>s;
		if(s[0]=='f'){
			ll r1=0;
			cin>>r1;
			v.pb(r1);
			p*=r1;
			if(p>mx || sb==0){
				p/=r1;
				sb=0;
			}
			else{
				rmin=v.size();
			}
		}
		else if(s[0]=='a'){
			ans+=p;
			if(ans>mx || sb==0){
				ok=0;
				l=0;
			}
		}
		else{
			ll ck=v.size();
			if(ck>0){
				ll kd=v[v.size()-1];
				v.po();
				if(v.size()==rmin){
					sb=1;
				}
				if(v.size()<rmin){
					p/=kd;
				}
			}
		}
	}
	if(ok){
		cout<<ans;
	}
	else{
		cout<<"OVERFLOW!!!";
	}
	cout<<endl;
	return 0;
}