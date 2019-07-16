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


int main(){             // D
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n; cin>>n;
                vll b(n), a;
                fol(i,0,n){
                        cin>>b[i];
                }
                sort(b.begin(), b.end());
                a.pb(b[0]);
                fol(i,1,n){
                        if(b[i]!=b[i-1]){
                                a.pb(b[i]);
                        }
                }
                n=a.size();
                vll exist(750005);
                fol(i,0,n){
                        exist[a[i]]=1;
                }
                reverse(a.begin(), a.end());
                ll ans=0, mx=a[0];
                fol(i,0,n){
                        for(ll j=2*a[i]; j<=mx; j+=a[i]){
                                if(exist[j]){
                                        exist[a[i]]+=exist[j];
                                        exist[a[i]]%=mod;
                                }
                        }
                        ans+=exist[a[i]];
                        ans%=mod;
                }
                cout<<ans<<endl;
        }
	return 0;
}