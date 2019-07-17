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

bool doit(const pair<ll,ll> &a, const pair<ll,ll> &b){
        if(a.ff!=b.ff){
                return a.ff<b.ff;
        }
        return a.ss>b.ss;
}
int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n; cin>>n;
        vector<pair<ll,ll> > a(n);
        for(i,0,n){
                cin>>a[i].ff>>a[i].ss;
        }
        sort(a.begin(), a.end(), doit);
        map<ll,ll> mp;
        mp[a[0].ff]++;
        for(i,1,n){
                if(a[i].ff==a[i-1].ff){
                        mp[a[i].ss]++;
                }
                else{
                        mp[a[i].ff]++;
                }
        }
        ll mx=0;
        for(i,0,n){
                if(mp[a[i].ff]>1 || mp[a[i].ss]>1){
                        cout<<-1<<endl;
                        return 0;
                }
                else{
                        if(mp[a[i].ff]==1){
                                mx=max(mx,a[i].ff);
                        }
                        if(mp[a[i].ss]==1){
                                mx=max(mx,a[i].ss);
                        }
                }
        }
        cout<<mx<<endl;
    	return 0;
}