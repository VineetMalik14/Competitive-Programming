#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef long double ld;
#define mod         ll(1000000007)
#define mod1        ll(998244353)
#define mox         ll(200005)
#define inf         ll(1e18)
#define fol(i,a,b)  for(ll i=a; i<b; i++)
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define mk          make_pair
#define pb          push_back
#define po          pop_back
#define ff          first
#define ss          second
#define bb          begin()
#define ee          end()
#define nn          '\n'
#define dbg(x)      cout << #x << " = " << x << '\n'
#define deci_pre(n) cout<<fixed<<setprecision(n)


ll gcd(ll a, ll b){
    ll mi=min(a, b), mx=max(a, b);
    while(mi!=0){
        ll temp=mi;
        mi=mx%mi;
        mx=temp;
    }
    return mx;
}

ll pw(ll x, ll n){
    if(x==0){
        return 0;
    }
    ll ans=1;
    while(n!=0){
        if(n&1ll){
            ans*=x;
        }
        x*=x;
        n>>=1ll;
    }
    return ans;
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
    ll a[4][4]={{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};
    ll ad=0;
    vector< vll > v(n, vll(n));
    for(ll i=0; i<n; i+=4){
        for(ll j=0; j<n; j+=4){
            for(ll k=0; k<4; k++){
                for(ll l=0; l<4; l++){
                    v[i+k][j+l]=ad+a[k][l];
                }
            }
            ad+=16;
        }
    }
    fol(i,0,n){
        fol(j,0,n){
            cout<<v[i][j]<<' ';
        }
        cout<<nn;
    }
	return 0;
}