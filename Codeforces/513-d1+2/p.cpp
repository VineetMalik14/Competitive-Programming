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
#define R 2005
#define C 2005

ll A[2005][2005], B[R][C], aux[R][C]; 
ll n, m; 
ll x;

void preProcess(ll mat[M][N]){ 
   // Copy first row of mat[][] to aux[][] 
   for (ll i=0; i<N; i++) 
      aux[0][i] = mat[0][i]; 
   // Do column wise sum 
   for (ll i=1; i<M; i++) 
      for (ll j=0; j<N; j++) 
         aux[i][j] = mat[i][j] + aux[i-1][j]; 
   // Do row wise sum 
   for (ll i=0; i<M; i++) 
      for (ll j=1; j<N; j++) 
         aux[i][j] += aux[i][j-1]; 
}
ll sumQuery(ll aux[M][N], ll tli, ll tlj, ll rbi, ll rbj){ 
        ll res = aux[rbi][rbj]; 
        if (tli > 0) 
                res = res - aux[tli-1][rbj]; 
        if (tlj > 0) 
                res = res - aux[rbi][tlj-1];  
        if (tli > 0 && tlj > 0)
                res = res + aux[tli-1][tlj-1]; 
        return res; 
}
ll maxHist(ll row[]){ 
    // Create an empty stack. The stack holds indexes of 
    // hist[] array/ The bars stored in stack are always 
    // in increasing order of their heights. 

    stack<ll> result; 
    ll top_val;     // Top of stack 
    ll max_area = 0; // Initialize max area in current row (or histogram) 
    ll area = 0;    // Initialize area with current top 
    // Run through all bars of given histogram (or row) 
    ll i = 0; 
    while (i < C) 
    { 
        // If this bar is higher than the bar on top stack, 
        // push it to stack 
        if (result.empty() || row[result.top()] <= row[i]) 
            result.push(i++); 
  
        else
        { 
            // If this bar is lower than top of stack, then 
            // calculate area of rectangle with stack top as 
            // the smallest (or minimum height) bar. 'i' is 
            // 'right index' for the top and element before 
            // top in stack is 'left index' 
            top_val = row[result.top()]; 
            result.pop(); 
            area = top_val * i; 
  
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1 ); 
            max_area = max(area, max_area); 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate area 
    // with every popped bar as the smallest bar 
    while (!result.empty()) 
    { 
        top_val = row[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1 ); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
} 
  
// Returns area of the largest rectangle with all 1s in A[][] 
ll maxRectangle(ll A[][C]){ 
    // Calculate area for first row and initialize it as result 
        ll result = maxHist(A[0]); 
    // iterate over row to find maximum rectangular area considering each row as histogram 
        for(ll i = 1; i < R; i++){ 
                for (ll j = 0; j < C; j++){     // if A[i][j] is 1 then add A[i -1][j] 
                        if(A[i][j]<=x){
                                B[i][j] += B[i - 1][j];
                        } 
                } 
                result = max(result, maxHist(B[i])); 
        }
        return result; 
}
ll main(){ 
        cin>>n>>m;
        fol(i,0,n){
                cin>>a[i];
        }
        fol(i,0,m){
                cin>>b[i];
        }
        cin>>x;
        fol(i,0,n){
                fol(j,0,m){
                        A[i][j]=a[i]*b[j];
                        if(A[i][j]<=x){
                                B[i][j]=1;
                        }
                        else{
                                B[i][j]=0;
                        }
                        aux[i][j]=0;
                }
        }
        preProcess(A);
        cout<<maxRectangle(A); 
        return 0; 
}