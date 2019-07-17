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
#define MAXN ll(15000001) 
  
// Calculating SPF (Smallest Prime Factor) for every number till MAXN. Time Complexity : O(nloglogn)
ll spf[MAXN];                                   // stores smallest prime factor for every number 
map<ll,ll> mp;
ll mx=0;
void sieve(){ 
        spf[1]=1; 
        for(ll i=2; i<MAXN; i++){               // marking smallest prime factor for every number to be itself.                               
                spf[i]=i;                   
        } 
        for(ll i=4; i<MAXN; i+=2){              // separately marking spf for every even number as 2
                spf[i]=2; 
        }
        for(ll i=3; i*i<MAXN; i++){    
                if(spf[i]==i){                  // checking if i is prime
                        for(ll j=i*i; j<MAXN; j+=i){    // marking SPF for all numbers divisible by i 
                                if(spf[j]==j){          // marking spf[j] if it is not previously marked
                                        spf[j]=i;
                                }
                        }
                } 
        }
}
void getFactorization(ll x){    // A O(log n) function returning primefactorization by dividing by smallest prime factor at every step
        vll mp1; 
        while(x!=1){ 
                if(!binary_search(mp1.begin(), mp1.end(), spf[x])){
                        mp[spf[x]]++;
                        mx=max(mx,mp[spf[x]]);
                        mp1.pb(spf[x]);
                }
                x/=spf[x]; 
        }  
}
int main(){
        ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        sieve(); 
        ll n; cin>>n;
        vll a(n);
        ll ok=0;
        fol(i,0,n){
                cin>>a[i];
                if(i>=1 && a[i]!=a[i-1]){
                        ok=1;
                }
        } 
        if(!ok){
                cout<<-1<<endl;
                return 0;
        }
        ll k=a[0];
        fol(i,1,n){
                k=__gcd(k,a[i]);
        }
        fol(i,0,n){
                getFactorization(a[i]/k);
        }
        cout<<n-mx<<endl;
        return 0; 
}