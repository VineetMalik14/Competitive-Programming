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
        
        ll n, m; cin>>n>>m;
        if(n+m<5){
                cout<<0<<endl;
                return 0;
        }
        if(n==1 || m==1){
                if((n+m-1)%6<=3){
                        cout<<(n+m-1)-(n+m-1)%6<<endl;
                }
                else if((n+m-1)%6==4){
                        cout<<(n+m-3)<<endl;
                }
                else{
                        cout<<(n+m-2)<<endl;
                }
        }
        else if((n==2 && (m==7 || m==3)) || (m==2 && (n==7|| n==3))){
                cout<<n*m-2<<endl;
        }
        else if(n%2==0 || m%2==0){
                cout<<n*m<<endl;
        }
        else{
                cout<<n*m-1<<endl;
        }
    	return 0;
}