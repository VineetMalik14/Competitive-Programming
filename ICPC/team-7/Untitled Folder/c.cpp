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
        
        ll p, q, t;
        cin>>p>>q>>t;
        ll n; cin>>n;
        vll a(n+1);
        fol(i,0,n){
                cin>>a[i];
        }
        a[n]=q;
        vll c, v;
        ll sz=1;
        c.pb(1); v.pb(a[0]);
        fol(i,1,n+1){
                if(a[i]==a[i-1]){
                        c[sz-1]++;
                }
                else{
                        c.pb(1); v.pb(a[i]);
                        sz++;
                }
        }
        ll ans=mod*mox, f=0;
        if(v[0]!=p){
                ans=0;
                f=p;
        }
        else{
                if(a[0]!=0){
                        ans=1;
                        f=a[0]-1;
                }
        }
        fol(i,0,sz-1){
                if(ans>max((ll)0,max(v[i],p)+c[i]*t-v[i+1]+1) && max(v[i],p)+c[i]*t<q){
                        ans=max((ll)0,v[i]+c[i]*t-v[i+1]+1);
                        f=v[i+1]-1;
                }
        }
        cout<<f<<endl;
    	return 0;
}