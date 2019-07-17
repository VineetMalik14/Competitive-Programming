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

ll dp[50][2501][4]={0};

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n, T; cin>>n>>T;
	vector < pair<ll,ll> > a(n);
	fol(i,0,n){
		cin>>a[i].ff>>a[i].ss;
	}
	fol(i,0,n){
		fol(j,0,4){
			dp[i][0][j]=1;
		}
	}
	fol(i,1,n){
		fol(j,1,T+1){
			fol(k,0,4){
				dp[i][j][k]+=dp[i-1][j][k];
				dp[i][j][k]%=mod;
				if(a[i].ss!=k && a[i].ff<=j){
					dp[i][j][k]+=dp[i-1][j-a[i].ff][a[i].ss];
					dp[i][j][k]%=mod;
				}
			}
		}
	}
	cout<<dp[n-1][T][0]<<"\n";
	return 0;
}