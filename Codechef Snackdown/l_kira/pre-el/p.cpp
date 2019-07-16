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

string t, p; 
vll a;
ll n;

ll subs(ll m){
	m++;
	vll v(m);
	fol(i,0,m){
		v[i]=a[i];
	}
	sort(v.begin(), v.end());
	ll j=0, k=0;
	fol(i,0,n){
		if(j<v.size() && i+1==v[j]){
			j++;
		}
		else if(t[i]==p[k]){
			k++;
			if(k==p.length()){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t>>p;
	n=t.length();
	ll inp;
	fol(i,0,n){
		cin>>inp;
		a.pb(inp);
	}
	ll mid, low=0, high=n;
	if(!subs(0)){
		cout<<0<<endl;
		return 0;
	}
	while(low+1!=high){
		mid=(low+high+1)/2;
		if(subs(mid)){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	cout<<low+1<<endl;
	return 0;
}