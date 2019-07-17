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


ll merge(int arr[], int temp[], int left, int mid, int right) 
{ 
    ll inv_count = 0; 
  
    int i = left; /* i is index for left subarray*/
    int j = mid;  /* i is index for right subarray*/
    int k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above explanation/ 
              diagram for merge()*/
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
    /* Copy the remaining elements of left subarray 
     (if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
     (if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
}

ll _mergeSort(int arr[], int temp[], int left, int right){ 
    ll mid, inv_count = 0; 
    if(right>left){ 
        mid = (right + left)/2; 
        inv_count  = _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid+1, right); 
        inv_count += merge(arr, temp, left, mid+1, right); 
    }
    return inv_count; 
}
ll countSwaps(int arr[], int n){ 
    int temp[n]; 
    return _mergeSort(arr, temp, 0, n - 1); 
}

int main()
{
	ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t; cin>>t;
	while(t--){
		ll n, d; cin>>n>>d;
		vll a(n), pos(n+1);
		fol(i,0,n){
			cin>>a[i];
			pos[a[i]]=i;
		}
		ll ans=0;
		fol(i,1,d+1){
			vector < pair<ll,ll> > v;
			for(ll j=i; j<=n; j+=d){
				v.pb(mk(pos[j], j));
			}
			sort(v.bb, v.ee);
			int mrr[v.size()];
			for(ll j=0; j<v.size(); j++){
				mrr[j]=v[j].ss;
			}
			ans+=countSwaps(mrr, v.size());
			ll k=0;
			for(ll j=i; j<=n; j+=d){
				a[v[k].ff]=j;
				k++;
			}
		}
		ll ok=1;
		fol(i,0,n){
			if(a[i]!=i+1){
				ok=0;
			}
		}
		if(ok){
			cout<<ans<<"\n";
		}
		else{
			cout<<-1<<"\n";
		}
	}
	return 0;
}