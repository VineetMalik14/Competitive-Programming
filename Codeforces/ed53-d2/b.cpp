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

ll gcd(ll a , ll b){
	if(b==0) return  a;
	if(a==0) return b;
	return gcd(b,a%b) ;
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

vll v(mox);
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
        vll a(n), b(n);
        fol(i,0,n){
                cin>>a[i];
                v[a[i]]=i+1;
        }
        fol(i,0,n){
                cin>>b[i];
        }
        ll done=0;
        fol(i,0,n){
                if(v[b[i]]>done){
                        cout<<v[b[i]]-done<<" ";
                        done=v[b[i]];
                }
                else{
                        cout<<0<<" ";
                }
        }
	return 0;
}