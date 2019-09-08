#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef int ll;
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

ll v[300][300][600];
ll a[300][300];
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n, m; cin>>n>>m;
                fol(i,0,n) fol(j,0,m) fol(k,0,n+m-1) v[i][j][k]=0;
                
                vll mp(n+m-1), vp(n+m-1);
                fol(i,0,n){
                        fol(j,0,m){
                        	char c; cin>>c;
                                a[i][j] = (c=='0')?0:1;
                        }
                }
                fol(i,0,n){
                        fol(j,0,n){
                                if(a[j][m-1]){
                                        v[i][m-1][abs(i-j)]++;
                                        if(a[i][m-1]){
                                                vp[abs(i-j)]++;
                                        }
                                }
                        }
                }
                fol(i,0,n){
                        for(ll j=m-2; j>=0; j--){
                                fol(k,1,n+m-1){
                                        v[i][j][k]=v[i][j+1][k-1];
                                }
                                for(ll k=n-1; k>=0; k--){
                                        if(a[k][j]){
                                                v[i][j][abs(i-k)]++;
                                                if(a[i][j]){
                                                        vp[abs(i-k)]++;
                                                }

                                        }
                                }
                        }
                }
                fol(i,0,n){
                        fol(j,0,m){
                                if(a[i][j]){
                                        fol(k,1,n+m-1){
                                                mp[k]+=v[i][j][k];
                                        }
                                }
                        }
                }
                fol(i,1,n+m-1){
                        cout<<mp[i]-vp[i]/2<<" ";
                }
                cout<<endl;
        }
	return 0;
}