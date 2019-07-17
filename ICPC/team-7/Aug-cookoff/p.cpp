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

void binrep(ll bit[], ll n){
        fol(i,0,10){
                bit[i]=n%10;
                n/=10;
        }
}
ll cnt3(ll bit[]){
        ll r=0;
        fol(i,0,10){
                if(bit[i]==3){
                        r++;
                }
        }
        return r;
}
int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        ll t; cin>>t;
        while(t--){
                ll n; cin>>n;
                ll bit[10];
                binrep(bit,++n);
                while(cnt3(bit)<3){
                        n++;
                        binrep(bit,n);
                }
                cout<<n<<endl;
        }
    	return 0;
}