#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
#define inf ll(1e18)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define vll vector<ll>
#define mk make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()


ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		ll r, c; cin>>r>>c;
		vector < char > vn[50][50], vp[50][50];
		ll at[50][50]={0};
		fol(i,0,r){
			fol(j,0,c){
				char ch;
				cin>>ch;
				if(ch=='#'){
					at[i][j]=1;
				}
				else if(ch=='-'){

				}
				else{
					vn[i][j].pb(ch);
				}
			}
		}
		ll tim=50, ans=0;
		while(tim>=0){
			fol(i,0,r){
				fol(j,0,c){
					ll r1=vn[i][j].size();
					ans+=(r1*(r1-1))/2;
					vp[i][j].clear();
					fol(k,0,vn[i][j].size()){
						vp[i][j].pb(vn[i][j][k]);
					}
					vn[i][j].clear();
				}
			}
			fol(i,0,r){
				fol(j,0,c){
					fol(k,0,vp[i][j].size()){
						if(vp[i][j][k]=='U' && i-1>=0 && at[i-1][j]==0){
							vn[i-1][j].pb(vp[i][j][k]);
						}
						if(vp[i][j][k]=='D' && i+1<=r-1 && at[i+1][j]==0){
							vn[i+1][j].pb(vp[i][j][k]);
						}
						if(vp[i][j][k]=='L' && j-1>=0 && at[i][j-1]==0){
							vn[i][j-1].pb(vp[i][j][k]);
						}
						if(vp[i][j][k]=='R' && j+1<=c-1 && at[i][j+1]==0){
							vn[i][j+1].pb(vp[i][j][k]);
						}
					}
				}
			}
			tim--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}