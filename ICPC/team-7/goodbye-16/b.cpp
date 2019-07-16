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
        
        ll n; cin>>n;
        vll a(n);
        ll t=0, tot=0;
        string s;
        fol(i,0,n){
                cin>>a[i]>>s;
                if(tot==0){
                        t=0;
                        if(s[0]!='S'){
                                tot=1;
                                break;
                        }
                }
                else if(tot==20000){
                        t=2;
                        if(s[0]!='N'){
                                tot=1;
                                break;
                        }
                }
                else{
                        t=1;
                }
                if(s[0]=='N'){
                        tot-=a[i];
                        if(tot<0){
                                tot=1;
                                break;
                        }
                }
                else if(s[0]=='S'){
                        tot+=a[i];
                        if(tot>20000){
                                tot=1;
                                break;
                        }
                }
        }
        if(tot==0){
                cout<<"YES\n";
        }
        else{
                cout<<"NO\n";
        }
    	return 0;
}