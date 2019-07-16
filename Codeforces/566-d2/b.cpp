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

	ll h, w; cin>>h>>w;
	vector <string> s(h);
	ll cnt=0;
	string ans="NO\n";
	fol(i,0,h){
		cin>>s[i];
		fol(j,0,w){
			if(s[i][j]=='*'){
				cnt++;
			}
		}
	}

	ll up[h][w], dw[h][w], l[h][w], r[h][w];

	fol(i,0,w){
		up[0][i]=0;
		dw[h-1][i]=0;
	}
	fol(i,1,h){
		fol(j,0,w){
			if(s[i-1][j]=='*'){
				up[i][j]=up[i-1][j]+1;
			}
			else{
				up[i][j]=0;
			}
		}
	}
	fol(k,1,h){
		ll i=h-1-k;
		fol(j,0,w){
			if(s[i+1][j]=='*'){
				dw[i][j]=dw[i+1][j]+1;
			}
			else{
				dw[i][j]=0;
			}
		}
	}

	fol(i,0,h){
		l[i][0]=0;
		r[i][w-1]=0;
	}
	fol(i,1,w){
		fol(j,0,h){
			if(s[j][i-1]=='*'){
				l[j][i]=l[j][i-1]+1;
			}
			else{
				l[j][i]=0;
			}
		}
	}
	fol(k,1,w){
		ll i=w-1-k;
		fol(j,0,h){
			if(s[j][i+1]=='*'){
				r[j][i]=r[j][i+1]+1;
			}
			else{
				r[j][i]=0;
			}
		}
	}

	fol(i,0,h){
		fol(j,0,w){
			if(s[i][j]=='*' && up[i][j]*dw[i][j]*l[i][j]*r[i][j]>0 && 1+up[i][j]+dw[i][j]+l[i][j]+r[i][j]==cnt){
				ans="YES\n";
			}
		}
	}

	cout<<ans;
	return 0;
}