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
        vll a(n);
        fol(i,0,n){
                cin>>a[i];
        }
        sort(a.begin(), a.end());
        ll ans=0;
        fol(i,1,n){
                ans+=a[i]-a[i-1]-1;
        }
        cout<<ans<<endl;
    	return 0;
}