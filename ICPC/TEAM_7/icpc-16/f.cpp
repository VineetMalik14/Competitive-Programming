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

int main(){             // F
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n, m, d, D; cin>>n>>m>>d>>D;
                if(!(n*d<=m && n*D>=m)){
                        cout<<-1<<endl;
                }
                else{
                        ll k1=m/n, k2=m%n, done=0;
                        fol(i,0,n){
                                ll p=0;
                                if(k2){
                                        p=1;
                                        k2--;
                                }
                                fol(j,0,k1+p){
                                        cout<<i+1<<" "<<(done+j)%n+1<<endl;
                                }
                                done+=k1+p;
                        }
                }
        }
	return 0;
}