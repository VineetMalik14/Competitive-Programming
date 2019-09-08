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

vll pc;

bool prime(ll x){
	ll d=sqrt(x)+2;
	fol(i,2,d){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

bool good(ll x){
	fol(i,0,pc.size()){
		if(x%pc[i]==0){
			return false;
		}
	}
	return true;
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	pc.pb(8); pc.pb(27);
	fol(i,5,10000){
		if(prime(i)){
			pc.pb(i*i*i);
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vll a(n), act(n);
		set<ll> c[n];
		vector < pair<ll,ll> > v1;
		fol(i,0,n){
			cin>>a[i];
		}
		fol(i,0,n){
			fol(j,0,i){
				if(!good(a[i]*a[j])){
					v1.pb(mk(i, j));
				}
			}
		}
		ll tot=pw(2,n);
		fol(i,0,v1.size()){
			ll r1=v1[i].ff, r2=v1[i].ss, rk=0;
			set <ll> :: iterator j;
			for(j=c[r1].bb; j!=c[r1].ee; j++){
				act[*j]=1;
			}
			for(j=c[r2].bb; j!=c[r2].ee; j++){
				act[*j]=1;
			}
			fol(j,0,n){
				if(act[j]==1){
					rk++;
				}
				act[j]=0;
			}
			tot-=pw(2, n-2-rk);
			c[r1].insert(r2); c[r2].insert(r1);
		}
		cout<<tot<<"\n";
	}
	return 0;
}