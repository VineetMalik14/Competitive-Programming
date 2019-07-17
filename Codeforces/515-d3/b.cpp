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

    	ll n, r; cin>>n>>r;
        vll a(n+1);
        fol(i,1,n+1){
                cin>>a[i];
        }
        ll ans=0, prev=0;
        fol(i,1,n+1){
                ll p=0;
                if(i>prev){
                for(ll j=i+r-1; j>=i-r+1; j--){
                        if(j<=n && j>=1 && a[j]){
                                ans++;
                                p=j;
                                break;
                        }
                }
                if(p==0){
                        cout<<-1<<endl;
                        return 0;
                }
                prev=p+r-1;
                }
        }
        cout<<ans<<endl;
    	return 0;
}