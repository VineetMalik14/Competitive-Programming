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

vll rt, v, vis(6);
ll tok=0;
ll a[6]={4,8,15,16,23,42};


void solve(){
	if(rt.size()==6){
		if(tok==0){
			ll ok=1;
			fol(i,0,4){
				if(rt[i]*rt[i+1]!=v[i]){
					ok=0;
				}
			}
			if(ok==1){
				fflush(stdout);
				cout<<"!";
				fol(i,0,6){
					cout<<" "<<rt[i];
				}
				cout<<endl;
				tok=1;
			}
		}
		return ;
	}
	fol(i,0,6){
		if(vis[i]==0){
			vis[i]=1;
			rt.pb(a[i]);
			solve();
			rt.po();
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fol(i,0,4){
		fflush(stdout);
		cout<<"?"<<" "<<i+1<<" "<<i+2<<endl;
		ll t;
		cin>>t;
		v.pb(t);
	}
	solve();
	return 0;
}