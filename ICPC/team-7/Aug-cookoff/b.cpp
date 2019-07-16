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

    	ll t; cin>>t;
        while(t--){
                ll n, k, x; cin>>n>>k>>x;
                vll p(k);
                map<ll,ll> mp;
                ll ans=0, mx=0, mi=100*mod;
                fol(i,0,k){
                        cin>>p[i];
                        ans+=p[i];
                        mp[p[i]]=1;
                        mx=max(mx,p[i]);
                        mi=min(mi,p[i]);
                }
                ll diff=x-(mx-mi);
                ll k1=mx-1;
                while(k<n){
                        if(mx<mi+x){
                                ans+=mi+x;
                                x--;
                                k++;
                        }
                        else{
                                if(!mp[k1]){
                                        ans+=k1;
                                        k++;
                                }
                                k1--;
                        }
                }
                cout<<ans<<endl;
        }
    	return 0;
}