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
ll pw(ll x, ll y){ 
    	if(y==0)		return 1; 
    	else if(y%2==0) 	return pw(x,y/2)*pw(x,y/2); 
    	else			return x*pw(x,y/2)*pw(x,y/2); 
}


int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin>>s;
	ll n=s.length();
	vector<char> t;
		ll k1=n-1, k2=0, j=n, i;
		while(j>0){
			if(j%2==0){
				i=k1;
				k1--;
			}
			else{
				i=k2;
				k2++;
			}
			t.pb(s[i]);
			j--;
		}
		reverse(t.begin(), t.end());
		fol(i,0,n){
			cout<<t[i];
		}
		cout<<endl;
	return 0;
}