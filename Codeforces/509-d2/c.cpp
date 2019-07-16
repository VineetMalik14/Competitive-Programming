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

bool bysec(const pair<ll,ll> &a, const pair<ll,ll> &b){
        return (a.ss<b.ss);
}
int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n, m, d; cin>>n>>m>>d;
        vector<pair<ll,ll> > a(n), b(n);
        fol(i,0,n){
                cin>>a[i].ff;
                a[i].ss=i;
        }
        sort(a.begin(), a.end());
        fol(i,0,n){
                b[i].ss=a[i].ss;
                b[i].ff=0;
        }
        ll k=0, mt=0, i=0;
        while(i<n){
                if(a[i].ff>=a[mt].ff+d+1){
                        k=max(k,i-mt);
                        mt++;
                }
                else if(i==n-1){
                        k=max(k,n-mt);
                }
                i++;
        }
        ll lt[mox], k1=1;
        b[0].ff=1; lt[0]=a[0].ff; i=1;
        while(i<n){
                if(a[i].ff<lt[k1-1]+d+1){
                        k1=k1%k+1;
                }
                b[i].ff=k1; lt[k1-1]=a[i].ff; i++;
        }
        sort(b.begin(), b.end(), bysec);
        cout<<k<<endl;
        fol(i,0,n){
                cout<<b[i].ff<<" ";
        }
        cout<<endl;
    	return 0;
}