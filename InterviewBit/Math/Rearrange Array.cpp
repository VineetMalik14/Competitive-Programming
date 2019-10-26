vector<int> Solution::primesum(int A) {
    vector<bool> isprime(A+1,1);
    
    for(int i=2;i*i<=A;i++){
        for(int j=i*i;j<=A;j+=i){
            isprime[j]=0;
        }
    }
    
    vector<int> ans;
    
    for(int i=2;i<=A;i++){
        if(isprime[i] && isprime[A-i]){
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
    
}
