int Solution::sqrt(int A) {
    long long l=0,r=A;
    while(l<r){
        long long mid=(l+r)/2;
        if(mid*mid>=A){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    if(l*l>A)l=l-1;
    return l;
}

