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

	string a, b, c; cin>>a>>b>>c;
	vll v(3);
	ll ans=0;
	if(a==b){
		if(a==c){
			ans=0;
		}
		else{
			ans=1;
		}
	}
	else if(a==c){
		ans=1;
	}
	else if(b==c){
		ans=1;
	}
	else{
		vll v(3);
		v[0]=a[0]-'0';
		v[1]=b[0]-'0';
		v[2]=c[0]-'0';
		sort(v.bb, v.ee);
		if(a[1]==b[1]){
			if(b[1]==c[1]){
				int c=0;
				fol(i,1,3){
					if(v[i]==v[i-1]+1){
						c++;
					}
				}
				if(c==2){
					ans=0;
				}
				else if(c==1){
					ans=1;
				}
				else{
					if(v[1]-v[0]==2 || v[2]-v[1]==2){
						ans=1;
					}
					else{
						ans=2;
					}
				}
			}
			else{
				if(abs(a[0]-b[0])==1 || abs(a[0]-b[0])==2){
					ans=1;
				}
				else{
					ans=2;
				}
			}
		}
		else if(b[1]==c[1]){
				if(abs(c[0]-b[0])==1 || abs(c[0]-b[0])==2){
					ans=1;
				}
				else{
					ans=2;
				}
		}
		else if(a[1]==c[1]){
				if(abs(a[0]-c[0])==1 || abs(a[0]-c[0])==2){
					ans=1;
				}
				else{
					ans=2;
				}
		}
		else{
			ans=2;
		}
	}
	cout<<ans<<"\n";
	return 0;
}