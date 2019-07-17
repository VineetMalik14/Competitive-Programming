#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef double ld;
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


ll val(string s){
	ll r=0, p=1;
	fol(i,0,s.length()){
		ll j=s.length()-1-i;
		if(!isdigit(s[j])){
			break;
		}
		ll k=s[j]-'0';
		r+=k*p;
		p*=10;
	}
	return r;
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	vector <string> a(n);
	vll ans(n), ck(n);
	ll s=0;
	fol(i,0,n){
		cin>>a[i];
		ll k=val(a[i].substr(a[i].length()-5, 5));
		if(a[i][0]!='-'){
			s+=k;
			ans[i]=val(a[i].substr(0, a[i].length()-6));
		}
		else{
			s-=k;
			ans[i]=-val(a[i].substr(0, a[i].length()-6));
		}
		if(k==0){
			ck[i]=1;
		}
		
	}
	s/=100000;
	if(s<0){
		fol(i,0,n){
			if(a[i][0]=='-' && ck[i]==0 && s<0){
				ans[i]--;
				s++;
			}
		}
	}
	else if(s>0){
		fol(i,0,n){
			if(a[i][0]!='-' && ck[i]==0 && s>0){
				ans[i]++;
				s--;
			}
		}
	}
	fol(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}