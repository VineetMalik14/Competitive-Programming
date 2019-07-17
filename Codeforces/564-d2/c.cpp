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
	vll a(mox), b(mox), pos(mox);
	fol(i,1,n+1){
		cin>>a[i];
		pos[a[i]]=-1;
	}
	fol(i,1,n+1){
		cin>>b[i];
		pos[b[i]]=i;
	}
	ll i=n+1;
	if(b[n]!=0){
		i--;
		ll k1=b[i];
		ll ok=0;
		while(b[i]==k1){
			if(k1==1){
				ok=1;
				break;
			}
			i--;
			k1--;
		}
		if(ok!=1){
			i=n+1;
		}
		if(ok==1){
			ll av=0;
			fol(j,1,i){
				ll j1=n-i+1+j;
				if(pos[j1]<=av){
					av++;
				}
				else{
					ok=0;
					break;
				}
				//cout<<av<<endl;
			}
			if(ok==1){
				cout<<av<<endl;
				return 0;
			}
			else{
				i=n+1;
			}
		}
	}
	ll av=0;
	fol(j,1,i){
		ll j1=n-i+1+j;
		if(pos[j1]<=av){
			av++;
		}
		else{
			av=pos[j1]+1;
		}
		//cout<<av<<endl;
	}
	cout<<av<<endl;
	return 0;
}