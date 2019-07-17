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

    	ll n, k; cin>>n>>k;
	    string s; cin>>s;
	    vector<char> v(k);
	    ll f=0, b=0, j=0;
	    for(i,0,n){
		    if(s[i]=='('){
			    f++;
			    if(f<=k/2){
				    v[j]=s[i];
				    j++;
			    }
		    }
		    else{
			    b++;
			    if(b<=k/2){
				    v[j]=s[i];
				    j++;
			    }
		    }
	    }
	    for(i,0,k){
		    cout<<v[i];
	    }
	    cout<<endl;
    	return 0;
}