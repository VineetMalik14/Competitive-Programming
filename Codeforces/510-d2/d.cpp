#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define mod ll(1000000007)
#define mox ll(200005)
#define fol(i,a,b) for(ll i=a; i<b; i++)
#define pb push_back
#define po pop_back
#define mk make_pair
#define vll vector<ll>
#define ff first
#define ss second

int main(){
    	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
        
        ll n, k; cin>>n>>k;
        vll arr(n);
        fol(i,0,n){
                cin>>arr[i];
        }
        ll start=0, end=0, count=0, sum=arr[0];
        while(end<n){
                if(sum<k){
                        end++;
                        count+=end-start;
                        if(end<n){
                                sum+=arr[end];
                        }
                }
                else{
                        sum-=arr[start];
                        start++;
                }
        }
        cout<<count<<endl;
    	return 0;
}