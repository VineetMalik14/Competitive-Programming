#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll t; cin>>t;
            while(t--){
                    ll n; cin>>n;
                    string s; cin>>s;
                    ll p=0;
                    for(i,0,n/2){
                            if(abs((ll)s[i]-(ll)s[n-1-i])!=2 && abs((ll)s[i]-(ll)s[n-1-i])!=0){
                                    p=1;
                            }
                    }
                    if(p==0){
                            cout<<"YES\n";
                    }
                    
                    else
                    {
                            cout<<"NO\n";
                    }
                    
            }
    	return 0;
}