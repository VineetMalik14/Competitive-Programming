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
  
ll a[100005], b[100005];
ll pr=0;

void updateBIT(ll BITree[], ll n, ll i, ll val) { 
    // i in BITree[] is 1 more than the i in arr[] 
    i = i + 1; 
    while (i <= n){ 
        // Add 'val' to current node of BI Tree 
        if(a[i]==b[i]){
                if(val!=b[i]){
                        pr--;
                }
        }
        else{
                if(val==b[i]){
                        pr++;
                }
        }
        BITree[i] = val; 
        a[i]=val;
        i += i & (-i); 
    } 
}  
void updateRange(ll BITTree1[], ll n, ll val, ll l, ll r) { 
    // Update Both the Binary i Trees 
    // As discussed in the article 
  
    // Update BIT1 
    updateBIT(BITTree1,n,l,val); 
    updateBIT(BITTree1,n,r+1,-val);  
}   
ll *constructBITree(ll n){ 
    // Create and initialize BITree[] as 0 
    ll *BITree = new ll[n+1]; 
    for (ll i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    return BITree; 
} 
  
// Driver Program to test above function 
int main(){ 
        ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

        ll t; cin>>t;
        while(t--){
                ll n, q; cin>>n>>q;
                ll *BITTree1;
                BITTree1 = constructBITree(n);
                fol(i,1,n+1){
                        cin>>a[i];
                }
                fol(i,1,n+1){
                        cin>>b[i];
                }
                fol(i,1,n+1){
                        if(a[i]==b[i]){
                                pr++;
                        }
                }
                ll x, y, z, l, r, c;
                while(q--){
                        cin>>x>>y>>z;
                        l=pr^x;
                        r=pr^y;
                        c=pr^z;
                        updateRange(BITTree1, n, c, l, r);
                        cout<<pr<<endl;
                }
        }
        return 0; 
}