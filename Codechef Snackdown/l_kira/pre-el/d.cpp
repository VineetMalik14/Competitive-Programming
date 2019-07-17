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


int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		ll n, p, q; cin>>n>>p>>q;
		vector< pair<ll,ll> > v(n);
		fol(i,0,n){
			cin>>v[i].ff;
			v[i].ss=i;
		}
		sort(v.begin(), v.end());
		ll a1=1, b1=1, c1=0, i1, j1, k1;
		fol(i,0,n){
			fol(j,0,i){
				ll mid, low=0, high=n;
				ll a=v[i].ff, b=v[j].ff, c=v[0].ff;
				if((q*c*c) > q*(a*a+b*b)-2*(p*a*b)){
					continue ;
				}
				while(low+1!=high){
					mid=(low+1+high)/2;
					c=v[mid].ff;
					if((q*c*c) <= q*(a*a+b*b)-2*(p*a*b)){
						low=mid;
					}
					else{
						high=mid;
					}
				}
				while(low==i || low==j){
					low--;
				}
				if(low>=0){
					c=v[low].ff;
					if(c>abs(a-b) && (a*a+b*b-c*c)*(2*a1*b1) < (2*a*b)*(a1*a1+b1*b1-c1*c1)){
						i1=i; j1=j; k1=low;
						a1=v[i1].ff; b1=v[j1].ff; c1=v[k1].ff;
					}
				}
			}
		}
		if(c1!=0){
			cout<<v[k1].ss+1<<" "<<v[i1].ss+1<<" "<<v[j1].ss+1<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}