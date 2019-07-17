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
        
        ll q; cin>>q;
        while(q--){
                ll n, m; cin>>n>>m;
                char ch[n][m];
                map <ll,ll> mp;
                fol(i,0,n){
                        fol(j,0,m){
                                cin>>ch[i][j];
                                if(ch[i][j]=='*'){
                                        mp[j]++;
                                }
                        }
                }
                ll ans=n+m-1;
                fol(i,0,n){
                        int r1=0;
                        fol(j,0,m){
                                if(ch[i][j]=='.'){
                                        ch[i][j]='1';
                                        mp[j]++;
                                        r1++;
                                }
                        }
                        fol(j,0,m){
                                ans=min(ans, r1+n-mp[j]);
                        }
                        fol(j,0,m){
                                if(ch[i][j]=='1'){
                                        ch[i][j]='.';
                                        mp[j]--;
                                }
                        }
                }
                cout<<ans<<"\n";
        }
        
        return 0;
}