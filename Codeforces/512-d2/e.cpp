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

ll pow[64];
ll cnt1(ll x){
        ll r=0;
        fol(i,0,64){
                if(x/pow[63-i]){
                        r++;
                        x%=pow[63-i];
                }
        }
        return r;
}
int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n;
        cin>>n;
        vll a(n);
        ll t=1;
        fol(i,0,64){
                pow[i]=t;
                t*=2;
        }
        fol(i,0,n){
                cin>>a[i];
                a[i]=cnt1(a[i]);
        }
        vll mi(n+1), mx(n+1);
        mi[1]=a[0]; mx[1]=a[0];
        fol(i,1,n+1){
                if(a[i]<=mx[i] && a[i]>=mi[i]){
                        mi[i+1]=0;
                        mx[i+1]=min(64,mx[i]+a[i]);
                }
                else if(a[i]>mx[i]){
                        if(mi[i]+a[i]<=64){
                                mx[i+1]=min(64,mx[i]+a[i]);
                                mi[i]=min(mi[i],a[i]-mx[i]);
                        }
                        else{
                                mx[i]=max(mx[i],mi[i]+a[i]-(mi[i]+a[i])%64);
                        }
                }
                else if(a[i]<mx[i]){
                        mx[i]=min(64,mx[i]+a[i]);
                        mi[i]=min(mi[i],a[i]-mx[i]);
                }
        }
    	return 0;
}