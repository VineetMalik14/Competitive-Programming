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

ll n;
vector<pair<ll,ll> > a(100005);
vll b(100005);

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	cin>>n;
        fol(i,0,n){
                cin>>a[i].ff;
                a[i].ss=i;
        }
        sort(a.begin(), a.end());
        fol(i,0,n){
                ll add=a[i];
                ll j=i+add;
                while(j<n){
                        if(a[j]>a[i]){
                                
                        }
                }
        }
    	return 0;
}