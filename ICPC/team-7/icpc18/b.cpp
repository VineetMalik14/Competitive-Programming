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

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n, k; cin>>n>>k;
                ll ans=0, r;
                vll a;
                fol(i,0,n){
                        cin>>r;
                        if(r>k){
                                a.pb(r-k);
                                ans+=k;
                        }
                        else{
                                ans+=r;
                        }
                }
                n=a.size();
                sort(a.begin(), a.end());
                ll s1=0;
                if(n==1){
                        ans+=a[0];
                }
                else if(n>1){
                        fol(i,0,n-2){
                                s1+=a[i];
                        }
                        if(s1>a[n-2]){
                                ans+=a[n-1]-(s1+a[n-2])%2;
                        }
                        else{
                                ans+=a[n-1]-(a[n-2]-s1);
                        }
                }
                cout<<ans<<endl;
        }
	return 0;
}