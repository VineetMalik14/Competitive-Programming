#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define mk make_pair
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

ll gcd(ll a, ll b){
	if(b==0) return a;
	if(a==0) return b;
	return gcd(b,a%b);
}
ll binarySearch(vll a, ll l, ll r, ll x){
	ll mid;
	while(l<=r){
        	mid=l+(r-l)/2;
		if(a[mid]==x)		return mid;
		else if(a[mid]<x)	l=mid+1;
		else			r=mid-1;
	}
	return -1;
}
ll pw(ll x, ll y){ 
    	if(y==0)	return 1; 
	ll r=pw(x,y/2);
    	if(y%2==0) 	return r*r; 
    	else		return x*r*r; 
}


int main(){
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n; cin>>n;
	string s; cin>>s;
	vll a(n+1);
	fol(i,1,n+1){
		cin>>a[i];
	}
	vll p1(n+2), p2(n+2), p3(n+2), q1(n+2), q2(n+2), q3(n+2);
	ll r1=0, r2=0, r3=0, r4=0; 
	for(ll i=n; i>0; i--){
		p1[i]=max(p1[i],p1[i+1]);
		p2[i]=max(p2[i],p2[i+1]);
		p3[i]=max(p3[i],p3[i+1]);
		if(s[i-1]=='d'){
			p1[i]=1;
		}
		else if(s[i-1]=='r' && p1[i]){
			p2[i]=1;
		}
		else if(s[i-1]=='a' && p1[i] && p2[i]){
			p3[i]=1;
		}
	}
	for(ll i=1; i<=n; i++){
		q1[i]=max(q1[i],q1[i-1]);
		q2[i]=max(q2[i],q2[i-1]);
		q3[i]=max(q3[i],q3[i-1]);
		if(s[i-1]=='h'){
			q1[i]=1;
		}
		else if(s[i-1]=='a' && q1[i]){
			q2[i]=1;
		}
		else if(s[i-1]=='r' && q1[i] && q2[i]){
			q3[i]=1;
		}
	}
	fol(i,1,n+1){
		if(s[i-1]=='h' && p1[i] && p2[i] && p3[i]){
			r1+=a[i];
		}
		else if(s[i-1]=='a' && q1[i] && p1[i] && p2[i]){
			r2+=a[i];
		}
		else if(s[i-1]=='r' && q1[i] && q2[i] && p1[i]){
			r3+=a[i];
		}
		else if(s[i-1]=='d' && q1[i] && q2[i] && q3[i]){
			r4+=a[i];
		}
	}
	cout<<min(r1,min(r2,min(r3,r4)))<<endl;
	return 0;
}