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
                ll n, a; cin>>n;
                vll s(n+1);
                fol(i,0,n){
                        cin>>a;
                        s[i+1]=s[i]+a;
                }
                ll ans=1, k=1;
                while(k+s[min(k,n)]<n){
                        k+=s[k];
                        ans++;
                }
                cout<<ans<<endl;
        }
	return 0;
}