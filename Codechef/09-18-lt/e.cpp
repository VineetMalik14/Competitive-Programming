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
        
        ll t; cin>>t;
        while(t--){
                ll n, q; cin>>n>>q;
                vll a(n), b(n);
                fol(i,0,n){
                        cin>>a[i];
                }
                fol(i,0,n){
                        cin>>b[i];
                }
                ll pr=0;
                fol(i,0,n){
                        if(a[i]==b[i]){
                                pr++;
                        }
                }
                ll x, y, z, l, r, c;
                while(q--){
                        cin>>x>>y>>z;
                        l=pr^x;
                        r=pr^y;
                        c=pr^z;
                        ll pr1=0;
                        fol(i,0,n){
                                if(i>=l-1 && i<=r-1){
                                        a[i]=c;
                                }
                                if(a[i]==b[i]){
                                        pr1++;
                                }
                        }
                        pr=pr1;
                        cout<<pr<<endl;
                }
        }
    	return 0;
}