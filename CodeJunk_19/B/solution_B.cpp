#include <bits/stdc++.h>
using namespace std;

#define mod (long int)1000000007

int main()
{
        long int n;
        cin >> n;

        vector < long int > arr(n);
        for(long int i=0; i<n; i++){
                cin >> arr[i];
        }

        vector < pair < long int, long int > > count;
        count.push_back(make_pair(arr[0], 1));

        for(long int i=1; i<n; i++){
                if(arr[i] == count[count.size()-1].first){
                        count[count.size()-1].second++;
                }
                else{
                        count.push_back(make_pair(arr[i], 1));
                }
        }

        long int ans=0;
        for(long int i=0; i<count.size(); i++){
                ans = count[i].second + 2*ans;
                ans %= mod;
        }

        cout << ans << "\n";
        return 0;
}