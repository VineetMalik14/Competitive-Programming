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

    	ll n, k; cin>>n>>k;
        vll h(n), a(mox);
        fol(i,0,n){
                cin>>h[i];
                a[h[i]]++;
        }
        ll ans=0;
        sort(h.begin(), h.end());
        fol(i,0,h[n-1]-h[0]){
                ll j=h[n-1]-i;
                a[j-1]+=a[j];
        }
        fol(i,0,h[n-1]-h[0]){
                ll j=h[n-1]-i, s=0;
                while(j>h[0] && s+a[j]<=k){
                        s+=a[j];
                        j--;
                }
                ans++;
                j++;
                i=h[n-1]-j;
        }
        cout<<ans<<endl;
    	return 0;
}