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

int main(){             // A
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
        while(t--){
                ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
                if((x1-x2)*(y1-y2)==0){
                        if(x1-x2!=0){
                                if(x1>x2){
                                        cout<<"left\n";
                                }
                                else{
                                        cout<<"right\n";
                                }
                        }
                        else{
                                if(y1>y2){
                                        cout<<"down\n";
                                }
                                else{
                                        cout<<"up\n";
                                }
                        }
                }
                else{
                        cout<<"sad\n";
                }
        }
	return 0;
}