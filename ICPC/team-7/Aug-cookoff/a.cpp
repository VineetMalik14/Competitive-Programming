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
                ll n, k; cin>>n>>k;
                vll a(n);
                fol(i,0,n){
                        cin>>a[i];
                } 
                ll ans=0;
                fol(i,0,n){
                        if(i%2==1){
                                if(a[i]==1){
                                        if(ans>0){
                                                ans--;
                                        }
                                        else{
                                                ans++;
                                        }
                                }
                        }
                        else{
                                if(a[i]==1){
                                        ans++;
                                }
                        }
                }
                if(ans>=k){
                        cout<<1<<endl;
                }
                else{
                        cout<<2<<endl;
                }
        }
    	return 0;
}