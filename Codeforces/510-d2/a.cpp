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
        vll a(n);
        fol(i,0,n){
                cin>>a[i];
        }
        sort(a.begin(), a.end());
        ll mi=a[n-1], mx=a[n-1]+m;
        ll i=0;
        while(m>0 && i<n){
                m-=mi-a[i];
                i++;
        }
        if(m>0)
                mi=mi+1+(m-1)/n;
        cout<<mi<<" "<<mx<<endl;
    	return 0;
}