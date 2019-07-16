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
int isprime(ll n){
        ll c=sqrt(n);
        fol(i,2,c+1){
                if(n%i==0){
                        return 0;
                }
        }
        return 1;
}
int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        ll t; cin>>t;
        while(t--){
    	ll a, b;
            cin>>a>>b;
            if(a-b>1 || !isprime(a+b)){
                    cout<<"NO\n";
            }
            else
                cout<<"YES\n";
        }
    	return 0;
}