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
        
        ll n, m, x; cin>>n>>m>>x;
        vll a(n), b(m);
        fol(i,0,n){
                cin>>a[i];
                a[i]%=x;
        }
        fol(i,0,m){
                cin>>b[i];
                b[i]%=x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll k1=0, k2=0;
        if(n!=1){
                k1=a[n-1]-a[0];
                fol(i,1,n){
                        k1=min(k1,a[i-1]-a[i]+x);
                }
        }
        if(m!=1){
                k2=b[m-1]-b[0];
                fol(i,1,m){
                        k2=min(k2,b[i-1]-b[i]+x);
                }
        }
        cout<<k1+k2<<endl;
    	return 0;
}