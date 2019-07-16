#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n; cin>>n;
	vll c(n), d(n);
	fol(i,0,n){
		cin>>c[i]>>d[i];
	}
	ll mx=mox*mod;
	fol(i,0,n){
		k+=c[i];
		if(d[i]==2){
			mx=mod;
		}
		if(mx==mod){
			if(i>0){
				k+=c[i];
				mx=1899;
				mi=1900-c[i];
			}
			else{
				mx=1899;
			}
		}
		else{
			k+=c[i];
			mx=1899;
			mi=1900-c[i];
		}
	}
	if(mx==mox*mod){
		cout<<"Impossible\n";
		return 0;
	}
    	return 0;
}