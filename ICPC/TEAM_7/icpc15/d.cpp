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
                ll temp=0, p=1;
                vll occ(n+1), a(n);
                fol(i,0,n){
                        if(i+1-k>=1 && occ[i+1-k]==0){
                                temp=i+1-k;
                        }
                        else{
                                temp=i+1+k;
                                if(i+1+k>n){
                                        cout<<-1<<endl;
                                        p=0;
                                        break;
                                }
                        }
                        a[i]=temp;
                        occ[temp]=1;
                }
                if(p){
                        fol(i,0,n){
                                cout<<a[i]<<" ";
                        }
                        cout<<endl;
                }
        }
	return 0;
}