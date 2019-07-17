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

ll cnt(ll n){
        ll r=0;
        while(n!=0){
                ll k=n%2;
                if(k){
                        r++;
                }
                n/=2;
        }
        return r;
}
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        ll p=1;
        vll p2(31);
        fol(i,0,31){
                p2[i]=p;
                p*=2;
        }
        while(t--){
                ll n; cin>>n;
                cout<<p2[cnt(n)]<<endl;
        }
	return 0;
}