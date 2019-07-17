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
        string s;
        cin>>s;
        vll a(n+1);
        fol(i,1,n+1){
                a[i]=a[i-1]+(ll)s[i-1]-48;
        }
        if(a[n]==0){
                cout<<"YES\n";
                return 0;
        }
        fol(i,1,901){
                if(a[n]%i==0 && a[n]/i>1){
                        ll k=0, p=1;
                        fol(j,1,n+1){
                                if(a[j]-a[k]==i){
                                        k=j;
                                }
                                else if(a[j]-a[k]>i){
                                        p=0;
                                        break;
                                }
                        }
                        if(p==1){
                                cout<<"YES\n";
                                return 0;
                        }
                }
        }
        cout<<"NO\n";
    	return 0;
}