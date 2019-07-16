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
        string s; cin>>s;
        vll ch(26);
        fol(i,0,n){
                ch[(ll)s[i]-97]++;
        }
        fol(i,0,26){
                while(ch[i]){
                        cout<<(char)(i+97);
                        ch[i]--;
                }
        }
	return 0;
}