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

    	vll a(14), tot(14);
    	for(i,0,14){
    		cin>>a[i];
    	}
    	for(i,0,14){
    		if(a[i]==0)
    			continue;
    		ll t1=a[i]/14, t2=a[i]%14;
    		ll t=a[i];
    		a[i]=0;
    		for(j,i+1,i+15){
    			ll p=0;
    			if(t2){
    				p=1;
    				t2--;
    			}
    			if((a[j%14]+t1+p)%2==0){
    				tot[i]+=a[j%14]+t1+p;
    			}
    		}
    		a[i]=t;
    	}
    	sort(tot.begin(), tot.end());
    	cout<<tot[13]<<endl;
    	return 0;
}