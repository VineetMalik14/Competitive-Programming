#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n, q; cin>>n>>q;
            ll k1=(n*n)/2 + n%2;
            while(q--){
                    ll x, y; cin>>x>>y;
                    ll ans=((x+y)%2)*k1;
                    ans+=((x-1)/2)*(n);
                    if(x%2==1){
                            ans+=(y+1)/2;
                    } 
                    else{
                            ans+=(n+(x+y+1)%2)/2;
                            ans+=(y+1)/2;
                    }
                    cout<<ans<<endl;
            }
    	return 0;
}