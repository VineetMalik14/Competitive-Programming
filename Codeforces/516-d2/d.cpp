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

ll n, m, ans=0;
char a[2000][2000]; int v[2000][2000];
ll lx[2000][2000]; ll rx[2000][2000];
void solve(ll r, ll c, ll x, ll y){
        if(v[r][c]==0){
                v[r][c]=1;
                ans++;
        }
        if(c<m-1 && y){
                if(v[r][c+1]==1){
                        if(x>lx[r][c+1] || y-1>rx[r][c+1]){
                                if(x>lx[r][c+1] && y-1>rx[r][c+1]){
                                        lx[r][c+1]=x;
                                        rx[r][c+1]=y-1;
                                }
                                solve(r,c+1,x,y-1);      
                        }
                }
                else if(a[r][c+1]=='.'){
                        lx[r][c+1]=x;
                        rx[r][c+1]=y-1;
                        solve(r,c+1,x,y-1);
                }
        }
        if(c>0 && x){
                if(v[r][c-1]==1){
                        if(x-1>lx[r][c-1] || y>rx[r][c-1]){
                                if(x-1>lx[r][c-1] && y>rx[r][c-1]){
                                        lx[r][c-1]=x-1;
                                        rx[r][c-1]=y;
                                }
                                solve(r,c-1,x-1,y);
                        }
                }
                else if(a[r][c-1]=='.'){
                        lx[r][c-1]=x-1;
                        rx[r][c-1]=y;
                        solve(r,c-1,x-1,y);
                }
        }
        if(r<n-1){
                if(v[r+1][c]==1){
                        if(x>lx[r+1][c] || y>rx[r+1][c]){
                                if(x>lx[r+1][c] && y>rx[r+1][c]){
                                        lx[r+1][c]=x;
                                        rx[r+1][c]=y;
                                }
                                solve(r+1,c,x,y);
                        }
                }
                else if(a[r+1][c]=='.'){
                        lx[r+1][c]=x;
                        rx[r+1][c]=y;
                        solve(r+1,c,x,y);
                }
        }
        if(r>0){
                if(v[r-1][c]==1){
                        if(x>lx[r-1][c] || y>rx[r-1][c]){
                                if(x>lx[r-1][c] && y>rx[r-1][c]){
                                        lx[r-1][c]=x;
                                        rx[r-1][c]=y;
                                }
                                solve(r-1,c,x,y);
                        }
                }
                else if(a[r-1][c]=='.'){
                        lx[r-1][c]=x;
                        rx[r-1][c]=y;
                        solve(r-1,c,x,y);
                }
        }
}
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        fol(i,0,2000){
                fol(j,0,2000){
                        v[i][j]=0;
                        lx[i][j]=0;
                        rx[i][j]=0;
                }
        }
	cin>>n>>m;
        ll r, c; cin>>r>>c;
        ll x, y; cin>>x>>y;
        fol(i,0,n){
                fol(j,0,m){
                        cin>>a[i][j];
                }
        }
        lx[r-1][c-1]=x;
        rx[r-1][c-1]=y;
        solve(r-1,c-1,x,y);
        cout<<ans<<endl;
	return 0;
}