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
        vll a(n);
        ll e=0, o=0;
        fol(i,0,n){
                cin>>a[i];
                if(a[i]%2==0){
                        e++;
                }
                else{
                        o++;
                }
        }
        if(e>o){
                cout<<"READY FOR BATTLE\n";
        }
        else{
                cout<<"NOT READY\n";
        }
	return 0;
}