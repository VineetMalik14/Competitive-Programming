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

int main(){
	//ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        ll a[100][100];
	ll t; cin>>t;
        while(t--){
                ll n, m; cin>>n>>m;
                fol(i,0,n){
                        fol(j,0,m){
                                scanf("%d", &a[i][j]);
                        }
                }
                ll mx=max(n,m)/2, ans=(-1)*mod, p1=0;
                fol(i,0,n){
                        fol(j,0,m){
                                p1=a[i][j];
                                fol(k,1,mx+1){
                                        if(i-k>=0 && i+k<=n-1 && j-k>=0 && j+k<=m-1){
                                                p1+=a[i-k][j-k]+a[i-k][j+k]+a[i+k][j-k]+a[i+k][j+k];
                                        }
                                        else{
                                                break;
                                        }
                                        ans=max(ans,p1);
                                }
                        }
                }
                fol(i,0,n-1){
                        fol(j,0,m-1){
                                p1=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                                ans=max(ans,p1);
                                fol(k,1,mx+1){
                                        if(i-k>=0 && i+1+k<=n-1 && j-k>=0 && j+k+1<=m-1){
                                                p1+=a[i-k][j-k]+a[i+k+1][j-k]+a[i-k][j+k+1]+a[i+k+1][j+k+1];
                                        }
                                        else{
                                                break;
                                        }
                                        ans=max(ans,p1);
                                }
                        }
                }
                printf("%d\n",ans);
        }
	return 0;
}