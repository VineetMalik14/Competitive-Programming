#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk make_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll binarySearch(ll a[], ll l, ll r, ll x){
        ll mid=(l+r)/2;
        if(x>a[mid]){
                return binarySearch(a,mid+1,r,x);
        }else if(x<a[mid]){
                return binarySearch(a,l,mid-1,x);
        }else if(x==a[mid]){
                return mid;
        }else{
                return 0;
        }
}
ll pw(ll a, ll b){
	ll ans=1;
	a%=mod; 
	assert(b>=0);
	for(;b;b>>=1){
		if(b&1){
			ans=ans*a%mod;
			a=a*a%mod;
		}
	}
	return ans;
}

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	
	return 0;
}