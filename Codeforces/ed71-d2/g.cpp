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
#define dbg(x)      cout << #x << " = " << x << '\n';
#define deci_pre(n)     cout<<fixed<<setprecision(n);


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
    vll a(n+1), b(n+1);
    vector<char> ch(n+1);
    fol(i,1,n+1){
        ll ty; cin>>ty;
        if(ty==2){
            cin>>b[n+1-i];
        }
        b[n+1-i]=n+1-b[n+1-i];
        cin>>ch[n+1-i];
    }
    fol(i,1,n+1){
        while(j<=n){
            
        }
    }
    ll m; cin>>m;
    fol(i,0,m){
        ll pos; cin>>pos;
        string t; cin>>t;
        pos=n+1-pos;
        ll lt=t.length();
        reverse(t.bb, t.ee);
        vll len(lt);
        ll j=1, k=0;
        while(j<lt){
            if(t[j]==t[k]){
                len[j]=k+1;
                j++;
                k++;
            }
            else{
                if(k==0){
                    len[j]=0;
                    j++;
                }
                else{
                    k=len[k-1];
                }
            }
        }
        ll cnt=0;
        j=pos; k=0;
        while(j<=n){
            if(ch[j]==t[k]){
                k++;
                if(k==lt){
                    cnt++;
                    k=len[k-1];
                }
                j=b[j];
            }
            else{
                if(k==0){
                    j=b[j];
                }
                else{
                    k=len[k-1];
                }
            }
        }
        cout<<cnt<<nn;
    }

	return 0;
}