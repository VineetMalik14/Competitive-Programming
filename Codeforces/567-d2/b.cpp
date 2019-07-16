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

string sum(string s1, string s2){
	char ch='0';
	ll d=0, k=0;
	string r="";
	fol(i,0,max(s1.length(), s2.length())){
		ll d1=0, d2=0;
		if(i<s1.length()){
			d1=s1[s1.length()-1-i]-'0';
		}
		if(i<s2.length()){
			d2=s2[s2.length()-1-i]-'0';
		}
		k=d1+d2+d;
		char ch1=ch+k%10;
		d=k/10;
		r=ch1+r;
	}
	char ch1=ch+d;
	if(ch1!='0'){
		r=ch1+r;
	}
	return r;
}


int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	string s; cin>>s;
	vll v(n);
	fol(i,1,n){
		if(s[i]!='0'){
			v[max(i,n-i)]++;
		}
	}
	string ans;
	fol(i,1,n){
		if(v[i]==1){
			string s1=s.substr(0,i), s2=s.substr(i,n-i);
			if(s2[0]!='0'){
				ans=sum(s1,s2);
			}
			else{
				s1=s.substr(0,n-i); s2=s.substr(n-i,i);
				ans=sum(s1,s2);
			}
			break;
		}
		else if(v[i]==2){
			string s1=s.substr(0,i), s2=s.substr(i,n-i);
			string a1=sum(s1,s2);
			s1=s.substr(0,n-i); s2=s.substr(n-i,i);
			string a2=sum(s1,s2);
			if(a1.length()>a2.length()){
				ans=a1;
			}
			else if(a1.length()<a2.length()){
				ans=a2;
			}
			else{
				if(a1<a2){
					ans=a1;
				}
				else{
					ans=a2;
				}
			}
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}