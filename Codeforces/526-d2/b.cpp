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


vll v1(mox), v2(mox); 

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, m; cin>>n>>m;
	vector < pair < ll , pair < ll , ll > > > a(n);
	fol(i,0,n){
		cin>>a[i].ss.ss;
		a[i].ss.ff=i+1;
	}
	fol(i,0,n){
		cin>>a[i].ff;
		v1[i+1]=a[i].ff;
		v2[i+1]=a[i].ss.ss;
	}
	sort(a.bb, a.ee);
	ll cnt=0;
	fol(i,0,m){
		ll t, d; cin>>t>>d;
		ll a1=0;
		if(v2[t]>=d){
			v2[t]-=d;
			a1+=d*v1[t];
			d=0;
		}
		else if(d>v2[t]){
			d-=v2[t];
			a1+=v2[t]*v1[t];
			v2[t]=0;
			ll ok=0;
			while(!ok){
				ll j=a[cnt].ss.ff;
				if(cnt==n){
					a1=0;
					break;
				}
				if(v2[j]>=d){
					v2[j]-=d;
					a1+=d*v1[j];
					d=0;
				}
				else if(d>v2[j]){
					d-=v2[j];
					a1+=v2[j]*v1[j];
					v2[j]=0;
					cnt++;
				}
				if(d==0){
					ok=1;
				}
			}
		}
		cout<<a1<<endl;
	}
	return 0;
}