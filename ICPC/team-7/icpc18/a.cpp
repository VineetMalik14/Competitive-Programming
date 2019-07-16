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

bool rp( pair < ll , pair<ll,ll> > a){
        if(a.ff==a.ss.ff && a.ff==a.ss.ss){
                return true;
        }
        return false;
}
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                string s; cin>>s;
                ll n=s.length();
                vector< pair < ll, pair<ll,ll> > > a;
                fol(i,0,n){
                        if(isdigit(s[i])){
                                ll k=s[i]-'0';
                                ll r=min(n,i+1+k);
                                ll l=max((ll)1,i+1-k);
                                a.pb(mk(i+1,mk(r,l)));
                        }
                }
                ll p=1;
                fol(i,0,a.size()){
                        fol(j,i+1,a.size()){
                                if((gcd(a[i].ss.ff-a[i].ss.ss, a[j].ss.ff-a[j].ss.ss)==1 && a[i].ss.ff >= a[j].ss.ss) || (a[i].ss.ff >= a[j].ss.ss && (rp(a[i]) || rp(a[j])))){
                                        p=0;
                                        break;
                                }
                        }
                }
                if(p){
                        cout<<"safe"<<endl;
                }
                else{
                        cout<<"unsafe"<<endl;
                }
        }
	return 0;
}