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

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n, m;
        cin>>n>>m;
        ll mi=max((ll)0,n-2*m);
        ll mx, k=0;
        while(m>(k*(k-1))/2){
                k++;
        }
        mx=max((ll)0,n-k);
        cout<<mi<<" "<<mx<<endl;
    	return 0;
}