int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    //int ans=0
    if(A.size()<=1){
        return 0;
    }else{
        int ans=0;
        int x=A[0];
        int y=B[0];
        for(int i=1;i<A.size();i++){
            int xnex=A[i];
            int ynex=B[i];
            
            int xdif=xnex-x;
            int ydif=ynex-y;
            
            int p=max(abs(xdif),abs(ydif));
            ans+=p;
            
            x=A[i];
            y=B[i];
            
            
        }
        return ans;
        
    }
    //return ans;
}

