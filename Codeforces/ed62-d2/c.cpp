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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll grand(ll x) {
    return uniform_int_distribution<ll>(0, x-1)(rng);
}

ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return (r*r)%mod; 
    	else		return (x*((r*r)%mod))%mod; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, k; cin>>n>>k;
	vector< pair<ll,ll> > a(n), b(n);
	vll s(n);
	fol(i,0,n){
		cin>>b[i].ss>>b[i].ff;
	}
	ll ans=0;
	sort(b.bb, b.ee);
	ll tot=0;
	s[n-1]=0;
	multiset<ll> st;
	fol(i,0,n){
		ll j=n-1-i;
		st.insert(b[j].ss);
		tot+=b[j].ss;
		if(st.size()>=k){
			ll r=*st.bb;
			tot-=r;
			st.erase(st.find(r));
		}
		if(j!=0){
			s[j-1]=tot;
		}
	}
	fol(i,0,n){	
		ans=max(ans, (s[i]+b[i].ss)*b[i].ff);
	}
	cout<<ans<<endl;
	return 0;
}