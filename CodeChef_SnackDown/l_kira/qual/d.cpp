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
                ll n; cin>>n;
                vll a(n), b(n);
                fol(i,0,n){
                        cin>>a[i];
                }
                fol(i,0,n){
                        cin>>b[i];
                }
                ll p=1;
                fol(i,0,n-2){
                        if(a[i]>b[i]){
                                p=0;
                        }
                        if(a[i]<=b[i]){
                                ll diff=b[i]-a[i];
                                a[i]+=diff;
                                a[i+1]+=2*diff;
                                a[i+2]+=3*diff;
                        }
                }
                fol(i,0,n){
                        if(a[i]!=b[i]){
                                p=0;
                        }
                }
                if(p){
                        cout<<"TAK\n";
                }
                else{
                        cout<<"NIE\n";
                }
        }
	return 0;
}