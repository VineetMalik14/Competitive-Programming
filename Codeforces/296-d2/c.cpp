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

	ll h, w, n; cin>>h>>w>>n;
	set<ll> cy, cx;
	multiset<ll> ly, lx;
	cy.insert(0); cy.insert(h);
	cx.insert(0); cx.insert(w);
	ly.insert(h); lx.insert(w);
	fol(i,0,n){
		char ch; ll d; cin>>ch>>d;
		if(ch=='V'){
			cy.insert(d);
			set<ll> :: iterator itr, itr1, itr2;
			itr=cy.find(d);
			itr1=itr; itr2=itr;
			++itr1; --itr2;
			ly.erase(ly.find(*(itr1)-*(itr2)));
			ly.insert(*(itr1)-*(itr));
			ly.insert(*(itr)-*(itr2));
		}
		if(ch=='H'){
			cx.insert(d);
			set<ll> :: iterator itr, itr1, itr2;
			itr=cx.find(d);
			itr1=itr; itr2=itr;
			++itr1; --itr2;
			lx.erase(lx.find(*(itr1)-*(itr2)));
			lx.insert(*(itr1)-*(itr));
			lx.insert(*(itr)-*(itr2));
		}
		cout<<(*(ly.rbegin()))*(*(lx.rbegin()))<<endl;
	}
	return 0;
}