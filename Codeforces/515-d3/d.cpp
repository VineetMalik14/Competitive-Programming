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

    	ll n , m ,k; cin>>n>>m>>k;
	vll a(n);
	fol(i,0,n){
		cin>>a[i];
	}
	reverse(a.begin(), a.end());
	ll i=0, r=k;
	while(i<n){
		if(r-a[i]<0){
			m--;
			if(m==0){
				break;
			}
			r=k;
		}
		r-=a[i];
		i++;
	}
	cout<<i<<endl;
    	return 0;
}