#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n, q; cin>>n>>q; 
	vll a(mox), b(mox), v(1);
	ll ok=0; v[0]=1;
	for(i,0,n){
		cin>>a[i];
		if(a[i]==q){
			ok=1;
		}
	}
	for(i,0,n){
		if(b[a[i]]){
			cout<<"NO\n";
			return 0;
		}
		if(!a[i]){
			if(!ok){
				a[i]=q;
				ok=1;
			}
			else{
				a[i]=v[v.size()-1];
			}
		}
		while(v[v.size()-1]>a[i]){
			ll y=v[v.size()-1];
			b[y]=1;
			v.po();
		}
		v.pb(a[i]);
	}
	if(!ok){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(i,0,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    	return 0;
}