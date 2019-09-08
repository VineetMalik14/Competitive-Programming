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

ll prime(ll n){
        ll r=1;
        fol(i,2,n){
                if(n%i==0){
                        r=0;
                }
        }
        return r;
}
ll semiprime(ll n){
        ll r=0;
        ll c=sqrt(n)+1;
        fol(i,2,c+1){
                if(n%i==0){
                        if(prime(i) && prime(n/i) && i!=n/i){
                                r=1;
                        }
                }
        }
        return r;
}
int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll n; cin>>n;
                string s="NO\n";
                fol(i,6,n-5){
                        if(semiprime(i) && semiprime(n-i)){
                                s="YES\n";
                                break;
                        }
                }
                cout<<s;
        }
	return 0;
}