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

int main(){             // B
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n; cin>>n;
                vll a(n);
                ll r=0, r1=0, r2=0;
                fol(i,0,n){
                        cin>>a[i];
                        if(a[i]!=1 && a[i]!=0 && a[i]!=-1){
                                r++;
                        }
                        if(a[i]==-1){
                                r1++;
                        }
                        if(a[i]==1){
                        	r2++;
                        }
                }
                if(r>1 || (r1>0 && r==1)){
                        cout<<"no\n";
                }
                else if(r1>1 && r2==0){
                	cout<<"no\n";
                }
                else{
                        cout<<"yes\n";
                }
        }
	return 0;
}