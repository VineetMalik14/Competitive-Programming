#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define for(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	//ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    	ll t; cin>>t;
            while(t--){
                    ll n; cin>>n;
                    vll a(n);
                    ll k1, k2;
                    ll pos;
                    for(i,0,n){
                            scanf("%lld",&a[i]);
                    }
                    sort(a.begin(), a.end());
                    for(i,0,n/2){
                            swap(a[i],a[n-1-i]);
                    }
                    ll k3=100000;
                    for(i,1,n){
                            if(a[i]==a[i-1]){
                                    k1=a[i];
                                    pos=i+2;
                                    break;
                            }
                    }
                    for(i,pos,n){
                                    if(a[i]==a[i-1]){
                                            k2=a[i];
                                            pos=i+2;
                                            break;
                                    }
                    }
                    for(i,pos,n){
                                    if(a[i]==a[i-1]){
                                            setprecision(15);
                                            if(((ld)a[i])/k3>((ld)k2)/k1){
                                                    k2=a[i];
                                                    k1=k3;
                                            }
                                            else if(((ld)a[i])/((ld)k2)>((ld)k2)/((ld)k1)){
                                                    k1=k2;
                                                    k2=a[i];
                                            }
                                            k3=a[i];
                                            i++;
                                    }
                    }
                    cout<<k1<<" "<<k1<<" "<<k2<<" "<<k2<<endl;
            }
    	return 0;
}