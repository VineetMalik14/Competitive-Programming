#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(998244353)
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
ll binarySearch(vll a, ll l, ll r, ll x){
	ll mid;
	while(l<=r){
        	mid=l+(r-l)/2;
		if(a[mid]==x)		return mid;
		else if(a[mid]<x)	l=mid+1;
		else			r=mid-1;
	}
	return -1;
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	string s; cin>>s;
	ll c1=1, c2=1;
	fol(i,1,n){
		if(s[i]==s[i-1]){
			c1++;
		}
		else{
			break;
		}
	}
	fol(i,1,n){
		ll j=n-1-i;
		if(s[j]==s[j+1]){
			c2++;
		}
		else{
			break;
		}
	}
	if(s[0]==s[n-1]){
		cout<<((c1+1)*(c2+1))%mod<<endl;
	}
	else{
		cout<<c1+c2+1<<endl;
	}
	return 0;
}