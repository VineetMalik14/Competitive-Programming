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


ll n, x;
ll a[21][21];
ll dp[21][21][100002];

ll solve(ll r, ll c, ll k){
	if(r>n || c>n){
		return 0;
	}
	if(r==n && c==n){
		if(k+a[n][n]<=x){
			return 1;
		}
		return 0;
	}
	return solve(r+1, c, k+a[r][c])+solve(r, c+1, k+a[r][c]);
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		cin>>n>>x;
		if(n<=10){
			fol(i,1,n+1){
				fol(j,1,n+1){
					cin>>a[i][j];
				}
			}
			ll ans=solve(1, 1, 0);
			cout<<ans<<"\n";
			continue;
		}
		fol(i,1,n+1){
			fol(j,1,n+1){
				cin>>a[i][j];
				fol(k,0,x+2){
					dp[i][j][k]=0;
				}
			}
		}
		fol(k,0,x+1){
			dp[n][n][k]=1;
		}
		for(ll j=n-1; j>=1; j--){
			fol(k,0,x+1){
				dp[n][j][k]=dp[n][j+1][min(x+1, k+a[n][j+1])];
			}
		}
		for(ll i=n-1; i>=1; i--){
			fol(k,0,x+1){
				dp[i][n][k]=dp[i+1][n][min(x+1, k+a[i+1][n])];
			}
		}
		for(ll i=n-1; i>=1; i--){
			for(ll j=n-1; j>=1; j--){
				fol(k,0,x+1){
					dp[i][j][k]=dp[i+1][j][min(x+1, k+a[i+1][j])]+dp[i][j+1][min(x+1, k+a[i][j+1])];
				}
			}
		}
		cout<<dp[1][1][a[1][1]]<<"\n";
	}
	return 0;
}