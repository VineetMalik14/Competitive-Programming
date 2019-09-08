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
    vll a(n);
    fol(i,0,n){
        cin>>a[i];
    }
    vll b=a;
    sort(b.bb, b.ee);
    b.resize(unique(b.bb, b.ee)-b.bb);
    vll pos(n), cnt(n);
    ll cn=0;
    fol(i,0,n){
        pos[i]=(ll)(lower_bound(b.bb, b.ee, a[i])-b.bb);
    }
    fol(i,0,n){
        cnt[pos[i]]++;
        if(cnt[pos[i]]==2){
            cn++;
        }
    }
    if(cn==0){
        cout<<0<<nn;
        return 0;
    }
    ll ans=n;
    fol(i,0,n){
        vll tmp=cnt;
        ll tn=0;
        fol(j,i,n){
            tmp[pos[j]]--;
            if(tmp[pos[j]]==1){
                tn++;
            }
            if(tn==cn){
                ans=min(ans, j-i+1);
            }
        }
    }
    cout<<ans<<nn;
	return 0;
}