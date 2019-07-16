#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(300005)
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

ll go[mox][19], last[mox][19];
vll v1[19];

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll pww[19]; 
	pww[0]=1;
	fol(i,1,19){
		pww[i]=2*pww[i-1];	
	}

	ll n, q; cin>>n>>q;
	vll a(n);
	fol(i,0,n){
		cin>>a[i];
		fol(j,0,19){
			if(ll(a[i]&pww[j])>0){
				v1[j].pb(i);
			}
		}
	}
	fol(j,0,n+1){
		fol(i,0,19){
			last[j][i]=n;
			go[j][i]=n;
		}
	}
	fol(i,0,19){
		ll pos=(ll)v1[i].size()-1;
		for(ll j=n-1; j>=0; j--){
			while(pos>=0 && v1[i][pos]>j){
				pos--;
			}
			if(pos+1<=(ll)v1[i].size()-1 && v1[i][pos+1]>j){
				last[j][i]=v1[i][pos+1];
			}
			else{
				last[j][i]=n;
			}
		}
	}
	for(ll i=n-1; i>=0; i--){
		fol(j,0,19){
			if(ll(a[i]&pww[j])>0){
				fol(k,0,19){
					go[i][k]=min(go[i][k],go[last[i][j]][k]);
				}
				go[i][j]=i;
			}
		}
	}
	fol(i,0,q){
		ll x, y; cin>>x>>y;
		string ans="Fou";
		fol(j,0,19){
			if(ll(a[y-1]&pww[j])>0 && go[x-1][j]<=y-1){
				ans="Shi";
				break;
			}
		}
		cout<<ans<<"\n";
	}
	/*fol(j,0,n+1){
		fol(i,0,19){
			cout<<j<<" "<<i<<" "<<go[j][i]<<"\n";
		}
	}
	fol(j,0,n+1){
		fol(i,0,19){
			cout<<j<<" "<<i<<" "<<last[j][i]<<"\n";
		}
	}
	fol(i,0,19){
		fol(j,0,v1[i].size()){
			cout<<v1[i][j]<<" ";
		}
		cout<<"\n";
	}
	fol(j,0,n){
		fol(i,0,19){
			cout<<j<<" "<<i<<" "<<ll(a[j]&pww[i])<<"\n";
		}
	}*/
	return 0;
}