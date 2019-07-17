#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
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
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}

vll pos(mox), a(mox), ans1, ans2;
ll r=0;
void bingo(ll c, ll b){
	ans1.pb(pos[c]);
	ans2.pb(pos[b]);
	swap(pos[c], pos[b]);
	a[pos[c]]=c;
	a[pos[b]]=b;
	r++;
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	fol(i,1,n+1){
		cin>>a[i];
		pos[a[i]]=i;
	}
	fol(i,1,n+1){

		ll p=pos[i], q=pos[a[i]];
		if(p==q){
			continue;
		}
		else{
			if(abs(p-q)>=n/2){
				bingo(p,q);
			}
			else{
				if(n-q>=n/2){
					bingo(q,n);
					if(n-p>=n/2){
						bingo(n,p);
					}
					else{
						bingo((ll)1,p);
						bingo((ll)1,n);
						bingo((ll)1,p);
					}
					bingo(q,n);
				}
				else{
					bingo(q,(ll)1);
					if(p-1>=n/2){
						bingo((ll)1,p);
					}
					else{
						bingo(n,p);
						bingo(n,(ll)1);
						bingo(n,p);
					}
					bingo(q,(ll)1);
				}
			}
		}
	}

	cout<<r<<endl;
	fol(i,0,r){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}