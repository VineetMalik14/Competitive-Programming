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
                ll n, m; cin>>n>>m;
                vector<pair<ll,ll> > a(n);
                vll b(n);
                fol(i,0,n){
                        cin>>a[i].ff>>a[i].ss;
                }
                sort(a.begin(), a.end());
                fol(i,0,n){
                        b[i]=a[i].ff;
                }
                ll x;
                while(m--){
                        cin>>x;
                        ll k=lower_bound(b.begin(), b.end(), x)-b.begin();
                        if(k<n && b[k]==x){
                                cout<<0<<endl;
                        }
                        else{
                                k--;
                                if(k==-1){
                                        cout<<a[k+1].ff-x<<endl;
                                }
                                else if(x<a[k].ss){
                                        cout<<0<<endl;
                                }
                                else if(k<n-1){
                                        cout<<a[k+1].ff-x<<endl;
                                }
                                else{
                                        cout<<-1<<endl;
                                }
                        }
                }
        }
    	return 0;
}