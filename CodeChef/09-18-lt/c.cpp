#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll t; cin>>t;
        while(t--){
                ll n; cin>>n;
                vll a(n);
                fol(i,0,n){
                        cin>>a[i];
                }
                if(n%2==0){
                        ll p=0;
                        fol(i,0,n){
                                if(i<n/2){
                                        if(a[i]==-1){
                                                if(a[i+n/2]!=-1){
                                                        a[i]=a[i+n/2];
                                                }
                                                else{
                                                        a[i]=1;
                                                        a[i+n/2]=1;
                                                }
                                        }
                                }
                                else{
                                        if(a[i]==-1){
                                                a[i]=a[i-n/2];
                                        }
                                }
                        }
                        fol(i,0,n/2){
                                if(a[i]!=a[i+n/2]){
                                        p=1;
                                        break;
                                }
                        }
                        if(p==0){
                                cout<<"YES\n";
                                fol(i,0,n){
                                        cout<<a[i]<<" ";
                                }
                        }
                        else{
                                cout<<"NO";
                        }
                }
                else{
                        cout<<"NO";
                }
                cout<<endl;
        }
    	return 0;
}