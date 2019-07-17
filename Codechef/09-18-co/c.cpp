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
                vll a[n];
                ll s=0, one=0;
                fol(i,0,n){
                        cin>>a[i];
                        s+=a[i];
                }
                ll l1=-1, r1=-1;
                fol(i,0,n){
                        if(a[i]==1 && l1==-1){
                                l1=i;
                        }
                        if(a[n-1-i]==1 && r1==-1){
                                r1=i;
                        }
                }
                if(l1==-1){
                        cout<<s/2<<endl;
                }
                else{
                        fol(i,0,n){
                                if(i>=l1)
                                        sr1+=a[i];
                                if(i<=l1)
                                        sl1+=a[i];
                                if(i>=r1)
                                        sr2+=a[i];
                                if(i<=r1)
                                        sl2+=a[i];
                        }
                        ss=max(max(sl1,sr1),max(sl2,sr2));
                        if(ss==max(sl1,sr1)){
                                if(sl1>sl2)
                        }
                }
        }
    	return 0;
}