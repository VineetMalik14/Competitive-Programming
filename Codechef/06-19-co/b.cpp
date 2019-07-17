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
		ll n, m; cin>>n>>m;
		vll c(m+1), d(n), f(n), b(n), r(m+1), ans(n);
		vector < pair<ll,ll> > v;
		fol(i,1,m+1){
			cin>>c[i];
		}
		fol(i,0,n){
			cin>>d[i]>>f[i]>>b[i];
			r[d[i]]++;
		}
		fol(i,1,m+1){
			if(c[i]>r[i]){
				v.pb(mk(i, c[i]-r[i]));
			}
		}
		ll tot=0;
		fol(i,0,n){
			if(c[d[i]]){
				tot+=f[i];
				ans[i]=d[i];
				c[ans[i]]--;
			}
			else{
				tot+=b[i];
				ans[i]=v[v.size()-1].ff;
				c[ans[i]]--;
				v[v.size()-1].ss--;
				if(v[v.size()-1].ss==0){
					v.po();
				}
			}
		}
		cout<<tot<<"\n";
		fol(i,0,n){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}