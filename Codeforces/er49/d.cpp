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

    	ll n; cin>>n;
	vll a(mox), c(mox);
	for(i,1,n+1){
		cin>>c[i];
	}
	for(i,1,n+1){
		cin>>a[i];
	}
	ll ans=0;
	vll v(mox), cnt(mox);
	for(i,1,n+1){
		ll t=i;
		if(!v[t]){
			ll t1=t, t2=t;
			t1=a[t1]; t2=a[a[t2]];
			while(t1!=t2 && !v[t1]){
				t1=a[t1];
				t2=a[a[t2]];
			}
			if(!v[t1]){
				ll a1=10000;
				while(cnt[t1]<1){
					cnt[t1]++;
					v[t1]=1;
					a1=min(a1,c[t1]);
					t1=a[t1];
				}
				ans+=a1;
			}
			t1=t;
			while(!v[t1]){
				v[t1]=1;
				t1=a[t1];
			}
		}
	}
	cout<<ans<<endl;
    	return 0;
}