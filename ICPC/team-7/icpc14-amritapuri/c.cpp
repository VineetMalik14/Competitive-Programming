#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk mkae_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        string s; cin>>s;
        ll n=s.length();
        vll a(n+1);
        fol(i,0,n){
                ll p=s[i]-'0';
                a[i+1]=a[i]*10+p;
        }
        ll q; cin>>q;
        while(q--){
                ll m, l; cin>>m>>l;
                vll md(m);
                ll ans=0;
                fol(i,1,n+1){
                        fol(j,0,m){
                                if(((a[i]%m)-j+m)%m==
                        }
                        if((a[i]%m)==l){
                                ans++;
                        }
                        md[a[i]%m]++;
                }
                cout<<ans<<endl;
        }
	return 0;
}