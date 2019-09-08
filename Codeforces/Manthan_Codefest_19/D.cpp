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
    vll a(n+1), pr(n+1), tl(n+1);
    map<ll, set<ll> > mp;
    oset st;
    fol(i,1,n+1){
        cin>>a[i];
        mp[a[i]].insert(-i);
    }
    ll s=0;
    fol(i,1,n+1){
        tl[i]=s;
        st.insert(s);
        s+=i;
    }
    s=0;
    fol(i,1,n+1){
        if(mp[s].size()==0){
            st.erase(s);
        }
    }
    fol(i,1,n+1){
        if(mp[tl[i]].size()!=0){
            ll r=tl[i];
            ll pos=-*mp[r].bb;
            pr[pos]=i;
            mp[r].erase(-pos);
            if(mp[r].size()==0){
                st.erase(r);
            }
        }
        else{
            ll k=st.order_of_key(tl[i]);
            ll r=*st.find_by_order(k);
            ll pos=-*mp[r].bb;
            pr[pos]=i;
            mp[r].erase(-pos);
            if(mp[r].size()==0){
                st.erase(r);
            }
        }
    }
    fol(i,1,n+1){
        cout<<pr[i]<<" ";
    }
    cout<<nn;
	return 0;
}