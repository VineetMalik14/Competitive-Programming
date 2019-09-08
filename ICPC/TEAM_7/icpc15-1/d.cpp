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

	ll n; cin>>n;
        ll q; cin>>q;
        set<ll> pt;
        multiset<pair<ll,pair<ll,ll>> > ln;
        while(q--){
                ll c1, c2; cin>>c1;
                if(c1==2){
                        cin>>c2;
                        auto it=pt.find(c2);
                        if(pt.size())
                        auto it1=it; auto it2=it;
                        ++it1; --it2;
                        ll p1=*it1, p2=*it2, p0=*it;
                        pt.erase(it);
                        ln.erase(*ln.find({dist[p1]-dist[p0],{p1,p0}}));
                        ln.erase(*ln.find({dist[p0]-dist[p2],{p0,p2}}));     
                }
                else{
                        pt.insert()
                }
        }
	return 0;
}