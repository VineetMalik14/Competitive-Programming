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

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        ll cnt[1000005];
        cnt[0]=1;
        fol(i,1,1000005){
                if(i%2==1){
                        cnt[i]=cnt[i-1]*i;
                        cnt[i]%=mod;
                }
                else{
                        cnt[i]=cnt[i-1];
                }
        }
	ll t; cin>>t;
        while(t--){
                ll n; cin>>n;
                vll a(n);
                fol(i,0,n){
                        cin>>a[i];
                }
                sort(a.begin(), a.end());
                ll sz=1;
                vll c;
                c.pb(1);
                fol(i,1,n){
                        if(a[i]!=a[i-1]){
                                c.pb(1);
                                sz++;
                        }
                        else{
                                c[sz-1]++;
                        }
                }
                ll ans=cnt[c[0]], done=c[0];
                fol(i,1,sz){
                        if(c[i]%2==1){
                                ans*=cnt[c[i]];
                                ans%=mod;
                        }
                        else{
                                if(done%2==0){
                                        ans*=cnt[c[i]];
                                        ans%=mod;
                                }
                                else{
                                        ans*=(cnt[c[i]]*c[i])%mod;
                                        ans%=mod;
                                }
                        }
                        done+=c[i];
                }
                cout<<ans%mod<<endl;
        }
	return 0;
}