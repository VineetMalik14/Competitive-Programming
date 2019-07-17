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


ll solve(ll mx, ll n, ll len){
	ll r=1, dd=n;
	while(mx>=0){
		ll d1=pw(2,mx);
		ll cnt=dd/d1;
		cnt-=cnt/2;
		r*=cnt; r%=mod;
		cnt--;
		len--;
		fol(i,0,cnt){
			r*=len; r%=mod;
			len--;
		}
		mx--;
	}
	return r;
}

ll solve1(ll mx, ll n, ll len){
	ll r=1, dd=n, p=0;
	while(mx>=0){
		ll d1=pw(2,mx);
		ll cnt=dd/d1;
		if(p)
		cnt-=cnt/2;
		else{
			p=1;
			cnt-=cnt/3;
		}
		r*=cnt; r%=mod;
		cnt--;
		len--;
		fol(i,0,cnt){
			r*=len; r%=mod;
			len--;
		}
		mx--;
	}
	return r;
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	ll mx=0;
	while(pw(2,mx)<=n){
		mx++;
	}
	mx--;
	ll other=0;
	if(3*(pw(2,mx-1))<=n){
		other=1;
	}
	ll ans=1, m1=mx, n1=n, dd=n;
	ans*=solve(m1, n, n); ans%=mod;
	//cout<<ans<<endl;
	if(other){
		ll ans1=1, r=1;
		for(ll i=m1-1; i>=0; i--){
			ll r1=r, n2=n1;
			ll d1=3*pw(2,i);
			ll cnt=dd/d1;
			cnt-=cnt/2;
			r*=cnt; r%=mod;
			cnt--;
			n1--;
			fol(i,0,cnt){
				r*=n1; r%=mod;
				n1--;
			}
			//cout<<r<<endl;
			r*=solve1(i, n, n1); r%=mod;
			//cout<<r<<endl;
			ans+=r; ans%=mod;
			
			r=r1; n1=n2;
			d1=3*pw(2,i);
			cnt=dd/d1;
			cnt-=cnt/2;
			r*=cnt; r%=mod;
			cnt--;
			n1--;
			fol(i,0,cnt){
				r*=n1; r%=mod;
				n1--;
			}
			//cout<<r<<endl;
			
		}
	}
	cout<<ans<<endl;
	return 0;
}