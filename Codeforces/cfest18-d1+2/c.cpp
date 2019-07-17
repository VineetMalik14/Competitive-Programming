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
        ll ans=0, k=0;
        map<ll,ll> mp;
        string a, b; cin>>a>>b;
        fol(i,1,n){
                if(a[i]!=b[i] && a[i-1]!=b[i-1] && a[i]!=a[i-1] && mp[i-1]!=1){
                        mp[i]=1; mp[i-1]=1;
                }
        }
        fol(i,0,n){
                if(a[i]!=b[i] && mp[i]!=1){
                        ans++;
                }
        }
        fol(i,0,n){
                if(mp[i]==1){
                        k++;
                }
        }
        ans+=k/2;
        cout<<ans<<endl;
    	return 0;
}