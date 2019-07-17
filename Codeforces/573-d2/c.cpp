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

	ll n, m, k; cin>>n>>m>>k;
	vll p(m);
	fol(i,0,m){
		cin>>p[i];
	}
	ll cnt=0, ans=0;
	while(cnt<m){
		ll s1=((p[cnt]-1-cnt)/k)*k;
		ll c1=0, i1=cnt, k1=k;
		while(true){
			c1=0;
			while(i1<m && p[i1]-cnt<=s1+k1){
				c1++;
				i1++;
			}
			if(c1==0){
				cnt=i1;
				break;
			}
			else{
				cnt+=c1;
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}