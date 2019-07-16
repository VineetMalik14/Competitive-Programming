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

ll cnt(ll n){
        ll r=0;
        while(n!=0){
                r+=n%10;
                n/=10;
        }
        return r;
}
int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        string s; cin>>s;
        ll n1=0, n2=0, n=s.length();
        fol(i,0,n){
                n1*=10; 
                n1+=(ll)s[i]-48;
        }
        fol(i,0,n-1){
                n2*=10;
                n2+=9;
        }
        //cout<<n1<<" "<<n2<<endl;
        ll ans=cnt(n1-n2)+cnt(n2);
        cout<<ans<<endl;
    	return 0;
}