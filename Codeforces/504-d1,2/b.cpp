#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define md ll(1000000007)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n, k; cin>>n>>k;
	    ll ans=0;
	if(n>=k-1){
		ans=(k-1)/2;
	}
	else{
		ans=max((ll)0,n-(k)/2);
	}
	cout<<ans;
    	return 0;
}