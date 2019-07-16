#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(998244353)
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

    	ll n, m; cin>>n>>m;
        string a, b; cin>>a>>b;
        vll arr(n), v(n+1);
        ll p=1;
        fol(i,0,n){
                ll j=n-1-i;
                if(a[j]=='1'){
                        arr[j]=p%mod;
                }
                p*=2;
                p%=mod;
        }
        ll diff=m-min(n,m);
        m=min(n,m);
        fol(i,n-m,n){
                if(b[diff+i-(n-m)]=='1'){
                        v[i+1]=1;
                }
        }
        fol(i,0,diff){
                if(b[i]=='1'){
                        v[0]++;
                }
        }
        fol(i,1,n+1){
                v[i]+=v[i-1];
        }
        ll ans=0;
        fol(i,0,n){
                ans+=v[i+1]*arr[i];
                ans%=mod;
        }
        cout<<ans%mod<<endl;
    	return 0;
}