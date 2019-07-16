#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
#define inf ll(1e18)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define vll vector<ll>
#define mk make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()


ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	vll a(n);
	ll ans=0;
	fol(i,0,n){
		cin>>a[i];
	}
	sort(a.bb, a.ee);
	ll c1=0, p1=0;
	fol(i,1,n){
		if(a[i]==a[i-1]){
			p1=i;
			c1++;
		}
	}
	if(c1>1){
		ans=1;
		if(ans){
			cout<<"cslnb\n";
		}
		else{
			cout<<"sjfnb\n";
		}
		return 0;
	}
	else if(c1==1){
		if(p1==1){
			if(a[p1]==0){
				ans=1;
				if(ans){
					cout<<"cslnb\n";
				}
				else{
					cout<<"sjfnb\n";
				}
				return 0;
			}
			else{
				a[p1-1]--;
			}
		}
		else{
			if(a[p1-2]==a[p1]-1){
				ans=1;
				if(ans){
					cout<<"cslnb\n";
				}
				else{
					cout<<"sjfnb\n";
				}
				return 0;
			}
			else{
				a[p1-1]--;
			}
		}
	}
	else{
		ll ok=0;
		fol(i,0,n){
			if(a[i]>i){
				a[i]--;
				ok=1;
				break;
			}
		}
		if(!ok){
			cout<<"cslnb\n";
			return 0;
		}
	}
	ll rk=0;
	fol(i,0,n){
		rk+=a[i]-i;
	}
	if(rk%2==1){
		ans=1;
		if(ans){
			cout<<"cslnb\n";
		}
		else{
			cout<<"sjfnb\n";
		}
		return 0;
	}
	ans=0;
	if(ans){
		cout<<"cslnb\n";
	}
	else{
		cout<<"sjfnb\n";
	}
	return 0;
}