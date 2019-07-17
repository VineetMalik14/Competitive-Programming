#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n; cin>>n;
        vll p(n);
        fol(i,0,n){
                cin>>p[i];
        }
        sort(p.begin(), p.end());
        ll sz=1;
        vll v, c;
        v.pb(p[0]); c.pb(1);
        fol(i,1,n){
                if(p[i]==p[i-1]){
                        c[sz-1]++;
                }
                else{
                        v.pb(p[i]); c.pb(1);
                        sz++;
                }
        }
        ll ans=1;
        fol(i,0,sz){
                ll k=min(v[i]-1, c[i]);
                ans*=k*v[i];
                ans%=mod;
        }
        cout<<ans<<endl;
    	return 0;
}