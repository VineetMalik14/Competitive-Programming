#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define md ll(1000000007)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n, m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	ll pos=-1;
	for(i,0,n){
		if(s[i]=='*'){
			pos=i;
		}
	}
	ll ans=1;
	if(pos==-1 && s!=t){
		ans=0;
	}
	if(m<n-1){
		ans=0;
		cout<<"NO\n";
		return 0;
	}
	for(i,0,pos){
		if(s[i]!=t[i]){
			ans=0;
		}
	}
	for(i,0,n-1-pos){
		if(s[n-1-i]!=t[m-1-i]){
			ans=0;
		}
	}
	if(ans==0){
		cout<<"NO\n";
	}
	
	else
	{
		cout<<"YES\n";
	}
	
    	return 0;
}