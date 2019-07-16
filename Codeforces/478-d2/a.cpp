#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define md ll(1000000007)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll n; cin>>n;
    	set<ll> a;
    	vll p(26);
    	p[0]=1;
    	for(i,1,26){
    		p[i]=p[i-1]*2;
    	}
    	for(i,0,n){
    		string s;
    		vll ch(26);
    		cin>>s;
    		for(j,0,s.length()){
    			ch[(ll)s[j]-97]++;
    		}
    		ll t=0;
    		for(i,0,26){
    			if(ch[i]){
    				t+=p[i];
    			}
    		}
    		a.insert(t);
    	}
    	cout<<a.size()<<endl;
    	return 0;
}