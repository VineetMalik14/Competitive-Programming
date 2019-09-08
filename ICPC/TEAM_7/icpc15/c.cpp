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

	ll n; cin>>n;
        vll a(n);
        fol(i,0,n){
                cin>>a[i];
        }
        sort(a.begin(), a.end());
        vll s(n+1);
        fol(i,1,n+1){
                s[i]=s[i-1]+a[i-1];
        }
        ll q; cin>>q;
        while(q--){
                ll k; cin>>k;
                ll t1=n/(k+1), t2=n%(k+1);
                if(t2){
                        t1++;
                }
                cout<<s[t1]<<endl;
        }
	return 0;
}