#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll a,b; cin>>a>>b;
	ll tot=a+b;
	ll t1[60000], t2[60000], a1[60000], a2[60000], b1[60000], b2[60000];
	ll r=sqrt(tot), k=0, k1=0, k2=0;
	for(i,1,r+1){
		if(tot%i==0){
			t1[k]=i;
			t2[k]=tot/i;
			k++;
		}
	}
	r=sqrt(a); k1=0;
	for(i,1,r+1){
		if(a%i==0){
			a1[k1]=i;
			a2[k1]=a/i;
			k1++;
		}
	}
	r=sqrt(b); k2=0;
	for(i,1,r+1){
		if(b%i==0){
			b1[k2]=i;
			b2[k2]=b/i;
			k2++;
		}
	}
	ll p=0;
	for(i,0,k){
		ll ta=max(t1[k-1-i], t2[k-1-i]);
		ll tb=min(t1[k-1-i], t2[k-1-i]);
		for(j,0,k1){
			ll aa=max(a1[k1-1-j], a2[k1-1-j]);
			ll ab=min(a1[k1-1-j], a2[k1-1-j]);
			if(ta>=aa && tb>=ab){
				p=1;
				break;
			}
		}
		for(j,0,k2){
			ll ba=max(b1[k2-1-j], b2[k2-1-j]);
			ll bb=min(b1[k2-1-j], b2[k2-1-j]);
			if(ta>=ba && tb>=bb){
				p=1;
				break;
			}
		}
		if(p==1){
			cout<<2*(ta+tb)<<endl;
			return 0;
		}
	}
    	return 0;
}