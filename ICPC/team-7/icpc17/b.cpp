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

	ll t; cin>>t;
        while(t--){
                ll n, g; cin>>n>>g;
                ld n1=n;
                cout<<fixed<<setprecision(12);
                if(n==1 && g!=0){
                	cout<<-1<<endl;
                  continue;
                }
                if(n%2==1){
                        cout<<0<<" ";
                }
                if(n-1){
                        ld ans;
                        if(n%2==1){
                                ans=(sqrt(n1)*g)/sqrt(n1-1);
                        }
                        else{
                                ans=g;
                        }
                        fol(i,0,n/2){
                                cout<<ans<<" ";
                        }
                        fol(i,0,n/2){
                                cout<<(-1)*ans<<" ";
                        }
                }
                cout<<endl;
        }
	return 0;
}