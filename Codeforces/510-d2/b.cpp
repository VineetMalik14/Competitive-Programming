#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(300005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n; cin>>n;
        vector<string> s(n); vll a(n);
        fol(i,0,n){
                cin>>a[i]>>s[i];
                sort(s[i].begin(), s[i].end());
        }
        ll c1, c2, c3, c4, c5, c6, c7;
        c1=mox;
        c2=mox;
        c3=mox;
        c4=mox;
        c5=mox;
        c6=mox;
        c7=mox;
        fol(i,0,n){
                if(s[i]=="A"){
                        c1=min(c1,a[i]);
                }
                if(s[i]=="B"){
                        c2=min(c2,a[i]);
                }
                if(s[i]=="C"){
                        c3=min(c3,a[i]);
                }
                if(s[i]=="AB"){
                        c4=min(c4,a[i]);
                }
                if(s[i]=="BC"){
                        c5=min(c5,a[i]);
                }
                if(s[i]=="AC"){
                        c6=min(c6,a[i]);
                }
                if(s[i]=="ABC"){
                        c7=min(c7,a[i]);
                }
        }
        ll ans=300005;
        ans=min(min(min(c1+c2+c3, c4+c5),min(c5+c6,c4+c6)),min(min(c1+c5,c2+c6),min(c3+c4,c7)));
        if(ans==300005){
                cout<<-1<<endl;
                return 0;
        }
        cout<<ans<<endl;
    	return 0;
}