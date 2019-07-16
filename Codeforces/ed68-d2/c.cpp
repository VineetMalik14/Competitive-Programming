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

bool subseq(string s, string t){
        ll j=0;
        fol(i,0,t.length()){
                if(j<s.length() && t[i]==s[j]){
                        j++;
                }
        }
        if(j==s.length()){
                return true;
        }
        return false;
}
bool countch(string s, string t){
        map <char,ll> mp;
        fol(i,0,t.length()){
                mp[t[i]]++;
        }
        fol(i,0,s.length()){
                mp[s[i]]--;
        }
        fol(i,0,t.length()){
                if(mp[t[i]]>0){
                        return false;
                }
        }
        return true;
}

int main()
{
        ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll q; cin>>q;
        while(q--){
                string s, t, p; cin>>s>>t>>p;
                if(subseq(s, t) && countch(s+p, t)){
                        cout<<"YES\n";
                }
                else{
                        cout<<"NO\n";
                }
        }
        
        return 0;
}