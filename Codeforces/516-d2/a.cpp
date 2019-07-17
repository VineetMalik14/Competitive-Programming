#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll a, b, c; cin>>a>>b>>c;
        ll ans=0, mx=max(a,max(b,c));
        ans=max((ll)0, mx+1-(a+b+c-mx));
        cout<<ans<<endl;
	return 0;
}