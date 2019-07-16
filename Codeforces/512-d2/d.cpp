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
        
        ll n, m, k;
        ll x1=0, x2=0, x3=0, y1=0, y2=0, y3=0;
        cin>>n>>m>>k;
        if(k!=2 && k/__gcd(n*m,k)>2){
                cout<<"NO\n";
                return 0;
        }
        cout<<"YES\n";
        if(k==2){
                x1=n;
                y2=m;
        }
        else{
                ll n1=n, m1=m;
        ll k1=__gcd(n*m,k);
        if(__gcd(n,k1)>=2){
                n1=n/__gcd(n,k1);
                if(k/k1==1){
                        n1*=2;
                }
                k1/=__gcd(n,k1);
                m1=m/__gcd(m,k1);
        }
        else{
                m1=m/__gcd(m,k1);
                if(k/k1==1){
                        m1*=2;
                }
        }
        x1=n1; y2=m1;
        }
        cout<<x1<<" "<<y1<<endl;
        cout<<x2<<" "<<y2<<endl;
        cout<<x3<<" "<<y3<<endl;
    	return 0;
}