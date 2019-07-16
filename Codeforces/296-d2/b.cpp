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
	string s, t; cin>>s>>t;
	ll ans=0, x=-2, y=-2, i=0, hd=0;
	vll v[26], pos[26]; vll exist(26);
	fol(i,0,n){
		if(s[i]!=t[i]){
			v[(ll)s[i]-97].pb(t[i]);
			pos[(ll)s[i]-97].pb(i);
			exist[(ll)s[i]-97]=1;
			hd++;
		}
	}
	while(ans<2 && i<n){
		if(s[i]!=t[i]){
			if(exist[(ll)t[i]-97]){
				if(binary_search(v[(ll)t[i]-97].begin(), v[(ll)t[i]-97].end(), s[i])){
					ans=2;
					ll k1=lower_bound(v[(ll)t[i]-97].begin(), v[(ll)t[i]-97].end(), s[i]) - v[(ll)t[i]-97].begin();
					x=pos[(ll)t[i]-97][k1];
					y=i;
				}
				else{
					ans=1;
					x=pos[(ll)t[i]-97][0];
					y=i;
				}
			}
		}
		i++;
	}
	cout<<hd-ans<<endl;
	cout<<x+1<<" "<<y+1<<endl;
	return 0;
}