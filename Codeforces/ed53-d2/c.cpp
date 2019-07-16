#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk make_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

ll gcd(ll a , ll b){
	if(b==0) return  a;
	if(a==0) return b;
	return gcd(b,a%b) ;
}
ll pw(ll a, ll b){
	ll ans=1;
	a%=mod; 
	assert(b>=0);
	for(;b;b>>=1){
		if(b&1){
			ans=ans*a%mod;
			a=a*a%mod;
		}
	}
	return ans;
}

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
        string s; cin>>s;
        ll x, y; cin>>x>>y;
        if((abs(x)+abs(y)-n)%2!=0){
                cout<<-1<<endl;
                return 0;
        }
        fol(i,0,n){
                if(s[i]=='U'){
                        u[i]++;
                        y1++;
                }
                else if(s[i]=='D'){
                        d[i]++;
                        y1--;
                }
                else if(s[i]=='L'){
                        l[i]++;
                        x1--;
                }
                else{
                        r[i]++;
                        x1++;
                }
        }
        ll x2=x-x1, y2=y-y1;
	return 0;
}