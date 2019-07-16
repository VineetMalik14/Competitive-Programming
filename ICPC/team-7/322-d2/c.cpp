#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n, k; cin>>n>>k;
        vll a(n), b(n);
        vector<pair<ll,ll> > c(n);
        ll s=0, t=0;
        fol(i,0,n){
                cin>>c[i].ss;
                b[i]=c[i].ss/10;
                s+=b[i];
                c[i].ff=c[i].ss%10;
        }
        sort(c.begin(), c.end());
        fol(i,0,n){
                if(c[i].ss<100){
                        b[i]=1;
                }
                else{
                        b[i]=0;
                }
        }
        fol(i,0,n){
                if(b[n-1-i]){
                        if(k-(10-c[n-1-i].ff)<0){
                                break;
                        }
                        k-=10-c[n-1-i].ff;
                        c[n-1-i].ss=((c[n-1-i].ss+10)/10)*10;
                        t++;
                }
        }
        ll ans=t+s, p=0;
        fol(i,0,n){
                        p+=10-c[i].ss/10;
        }
        ans+=min(k/10,p);
        cout<<ans<<endl;
    	return 0;
}