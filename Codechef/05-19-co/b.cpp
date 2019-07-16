#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mod1 ll(998244353)
#define mox ll(200005)
#define inf ll(1e18)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define vll vector<ll>
#define mk make_pair
#define pb push_back
#define po pop_back
#define ff first
#define ss second
#define bb begin()
#define ee end()


ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}

void print(string s, ll m){
	cout<<1;
	fol(i,1,(m+1)/2){
		cout<<0;
	}
	fol(i,0,(m)/2){
		cout<<9;
	}
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll m=s.length();
		if(s[0]!='1'){
			print(s,m);
		}
		else if(s[0]=='1'){
			ll pos=0;
			fol(i,1,(m+1)/2){
				if(s[i]!='0'){
					print(s,m);
					pos=-1;
					break;
				}
			}
			if(pos==0){
				ll done=0;
				fol(i,(m+1)/2,m){
					if(s[i]!='0'){
						done=1;
						ll ok=1;
						fol(j,i+1,m){
							if(s[j]!='9'){
								ok=0;
								break;
							}
						}
						if(ok==1){
							cout<<s;
						}
						else{
							cout<<1;
							fol(j,1,i){
								cout<<0;
							}
							s[i]--;
							cout<<s[i];
							fol(j,i+1,m){
								cout<<9;
							}
						}
						break;
					}
				}
				if(done==0){
					print(s,m-1);
				}
			}
		}

		cout<<endl;
	}
	return 0;
}