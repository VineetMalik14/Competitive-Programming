#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N = 1e6 + 7;
ll segtree[4*N]={0}, cnt = 0;
ll arr[100005], brr[100005];

ll mktree(ll arr[],ll l, ll r, ll pos){
    if(l==r){
        if(arr[l]==brr[l]){
                return 1;
        }
        else{
                return 0;
        }
    }
    ll mid = (l+r)/2;
    segtree[pos]+=mktree(arr, l, mid, 2*pos+1);
    segtree[pos]+=mktree(arr, mid+1, r, 2*pos+2);
    return segtree[pos];
}
ll update(ll arr[], ll l, ll r, ll ql, ll qr, ll val, ll pos){
    if(l==r){
        arr[l] = val;
        if(arr[l]==brr[l]){

        }
        return ;
    }
    ll mid = (l+r)/2;
    if(a>=l && a<=mid){
        update(arr, l, mid,a,val,2*pos+1);
    }
    else
        update(arr,mid+1,r,a,val,2*pos+2);
    segtree[pos] = __gcd(segtree[2*pos+1], segtree[2*pos+2]);
}
void query(ll arr[], ll l, ll r,ll ql, ll qr, ll val, ll pos){
    if(l>qr || r<ql)
        return ;
    if(l==r){
            arr[l]=val;
            if(segtree[pos]==0){
                    if(val==brr[pos]){
                            cnt++;
                            return ;
                    }
                    else{
                            return ;
                    }
            }
            else{
                    if(val==brr[pos]){
                            return ;
                    }
                    else{
                            cnt--;
                            return ;
                    }
            }
    }
    if(l>=ql && r<=qr){
        if(segtree[pos]%val==0)
            return ;
        if(segtree[pos]%val){
            if(segtree[2*pos+1]%val && segtree[2*pos+2]%val){
                cnt = 2;
                return ;
            }
        }
    }
    ll mid = (l+r)/2;
    (query(arr, l, mid, ql, qr, val, 2*pos+1));
    query(arr, mid+1, r, ql, qr, val, 2*pos+2);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);ll arr[n];
    ll t; cin>>ll arr[n];
    while(t--){ll arr[n];
        ll n;
        cin>>n;
        fill(segtree, segtree+N, 1);
        for(ll i=0;i<n;i++){
                cin>>arr[i];
        }
        for(ll i=0; i<n; i++){
                cin>>brr[i];
        }
        cnt=mktree(arr, 0, n-1, 0);
        ll q; cin>>q;
        for(ll i=0;i<q;i++){
                ll x, y, z, l, r, c;
                l=cnt^x; r=cnt^y; c=cnt^z;
                query(arr, 0, n-1, l-1, r-1, c, 0);
                cout<<cnt<<endl;
        }
    }
}